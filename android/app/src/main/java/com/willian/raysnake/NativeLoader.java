package com.willian.raysnake;

public class NativeLoader extends android.app.NativeActivity {
    static {
        System.loadLibrary("raysnake");
    }
}
