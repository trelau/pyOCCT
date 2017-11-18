#ifndef __ObjectPool_Templates_Header__
#define __ObjectPool_Templates_Header__

#include <pyOCCT_Common.hpp>

#include <ObjectPool.hxx>

// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\ObjectPool.hxx
template <typename X>
void bind_ObjectPool(py::object &mod, std::string const &name) {

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\ObjectPool.hxx
	py::class_<ObjectPool<X>, std::unique_ptr<ObjectPool<X>, Deleter<ObjectPool<X>>>> cls(mod, name.c_str(), "None");
	cls.def(py::init<int>(), py::arg("nblk"));
	cls.def("getNew", (X * (ObjectPool<X>::*)()) &ObjectPool<X>::getNew, "None");
	cls.def("destroy", (void (ObjectPool<X>::*)(X *)) &ObjectPool<X>::destroy, "None", py::arg("obj"));
	cls.def("clear", (void (ObjectPool<X>::*)()) &ObjectPool<X>::clear, "None");

};

#endif