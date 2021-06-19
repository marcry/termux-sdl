package com.termux.sdl;

import android.app.Activity;
import android.app.NativeActivity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardCopyOption;

public class TermuxNativeActivity extends Activity {

    private static final String TAG = "TermuxNativeActivity";

    // the default native app 
    private String nativeApp = "libnative_loader.so";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        if((getIntent().getFlags() & Intent.FLAG_ACTIVITY_BROUGHT_TO_FRONT) != 0) {
            this.finish();
            return;
        }
        super.onCreate(savedInstanceState);

        nativeApp = getIntent().getStringExtra("nativeApp");
        // copy libxxx.so to internal directory
        copyLibFile();
        
        Intent intent = new Intent(this, NativeActivity.class);
        // pass parameters to native_loader
        intent.putExtra("nativeApp", nativeApp);
        // start native app
        startActivity(intent);
        finish();
    }

    @Override
    protected void onNewIntent(Intent intent) {
        // TODO: Implement this method
        super.onNewIntent(intent);
    }
    
    public void copyLibFile() {
        if(nativeApp != null && !nativeApp.isEmpty()) {
            Path app = Paths.get(nativeApp);
            if(Files.exists(app)) {
                Path dir = Paths.get(getCacheDir().getParentFile().getAbsolutePath() + "/tmpdir");
                Path file = dir.resolve(app.getFileName());

                try {
                    if(!Files.exists(dir))
                        Files.createDirectories(dir);

                    Files.copy(app, file, StandardCopyOption.REPLACE_EXISTING);
                    Runtime.getRuntime().exec("chmod 755 " + file.toAbsolutePath()).waitFor();

                    // Environment variables must be set, otherwise the program will not run correctly
                    String pwd = app.getParent().toAbsolutePath().toString();
                    Log.i(TAG, "chdir: " + pwd);
                    JNI.chDir(pwd);
                    JNI.setEnv("PWD", pwd, true);
                    // nativeApp = /data/user/0/com.termux.sdl/tmpdir/libxxx.so
                    nativeApp = file.toAbsolutePath().toString();

                    FileOutputStream conf = new FileOutputStream(dir + "/native_loader.conf");
                    conf.write(nativeApp.getBytes());
                    conf.close();

                } catch(Exception e) {
                    e.printStackTrace();
                }
            }
        }
    }

    public void deleteLibFile() {
        // delete /data/user/0/com.termux.sdl/tmpdir/libxxx.so
        try {
            Files.deleteIfExists(Paths.get(nativeApp));
        } catch(IOException e) {
            e.printStackTrace();
        }
    }

    @Override
    protected void onStop() {
        super.onStop();
        deleteLibFile();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        deleteLibFile();
    }
}
