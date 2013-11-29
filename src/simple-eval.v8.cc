#include <v8.h>

using namespace v8;

int
main(int argc, char **argv) {
    Isolate *isolate = Isolate::GetCurrent ();
    HandleScope handle_scope (isolate);

    Handle<Context> context = Context::New (isolate);

    Context::Scope context_scope (context);

    Handle<String> source = String::New ("5 * 3");
    Handle<Script> script = Script::Compile (source);

    Handle<Value> result = script->Run ();

    if (!result.IsEmpty ()) {
        String::AsciiValue ascii (result);
        printf ("result: %s\n", *ascii);
    } else {
        printf ("no result\n");
    }
    return 0;
}
