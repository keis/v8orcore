#include <stdlib.h>
#include <stdio.h>
#include <JavaScriptCore/JavaScript.h>
#include <JavaScriptCore/JSContextRef.h>

int
main(int argc, char **argv) {
    JSGlobalContextRef ctx;
    JSObjectRef global;
    JSStringRef code, file, result_string;
    JSValueRef err = NULL, result;
    size_t buf_size;
    char *buf;

    ctx = JSGlobalContextCreate (NULL);
    global = JSContextGetGlobalObject (ctx);
    file = JSStringCreateWithUTF8CString ("<internal>");
    code = JSStringCreateWithUTF8CString ("5 * 3");
    result = JSEvaluateScript (ctx, code, global, file, 0, &err);

    if (result) {
        result_string = JSValueToStringCopy (ctx, result, NULL);
        buf_size = JSStringGetMaximumUTF8CStringSize (result_string);
        buf = malloc (buf_size);
        JSStringGetUTF8CString (result_string, buf, buf_size);
        printf ("result: %s\n", buf);
        free (buf);
    } else {
        printf ("no result\n");
    }

    return 0;
}
