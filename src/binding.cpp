#include "binding.h"

using namespace v8;

void RegisterModule(Handle<Object> target) {

	#ifdef is_linux
	    target->Set(String::New("HERTZ"), Number::New(sysconf(_SC_CLK_TCK)));
	    target->Set(String::New("PAGE_SIZE"), Number::New(sysconf(_SC_PAGESIZE)));
	#endif

	#ifdef is_solaris
	    target->Set(String::New("getUsage"), 
	        FunctionTemplate::New(GetUsage)->GetFunction());
	#endif

	    target->Set(String::New("OS"), String::New(OS));
}

NODE_MODULE(sysinfo, RegisterModule);