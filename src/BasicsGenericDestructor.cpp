#include <pyOCCT_Common.hpp>

#include <BasicsGenericDestructor.hxx>

PYBIND11_MODULE(BasicsGenericDestructor, mod) {

	// IMPORT

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\BasicsGenericDestructor.hxx
	py::class_<PROTECTED_DELETE, std::unique_ptr<PROTECTED_DELETE, py::nodelete>> cls_PROTECTED_DELETE(mod, "PROTECTED_DELETE", "The PROTECTED_DELETE base class provides a protected destructor. The only way to use PROTECTED_DELETE is inheritance: example: class LocalTraceBufferPool : public PROTECTED_DELETE Herited class destructor must stay protected. Normal use is: - create an instance of herited class on the heap (new), - use addObj(instance) to store the instance on the static list _objList, - delete instance with deleteInstance(instance)");
	cls_PROTECTED_DELETE.def(py::init<>());
	cls_PROTECTED_DELETE.def_static("deleteInstance_", (void (*)(PROTECTED_DELETE *)) &PROTECTED_DELETE::deleteInstance, "None", py::arg("anObject"));
	cls_PROTECTED_DELETE.def_static("addObj_", (void (*)(PROTECTED_DELETE *)) &PROTECTED_DELETE::addObj, "None", py::arg("anObject"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\BasicsGenericDestructor.hxx
	py::class_<GENERIC_DESTRUCTOR, std::unique_ptr<GENERIC_DESTRUCTOR, Deleter<GENERIC_DESTRUCTOR>>> cls_GENERIC_DESTRUCTOR(mod, "GENERIC_DESTRUCTOR", "The GENERIC_DESTRUCTOR abstract class describes the comportement of any destruction object. This type is used to create a list of miscellaneous destruction objects.");
	cls_GENERIC_DESTRUCTOR.def_static("Add_", (const int (*)(GENERIC_DESTRUCTOR &)) &GENERIC_DESTRUCTOR::Add, "None", py::arg("anObject"));
	cls_GENERIC_DESTRUCTOR.def("__call__", (void (GENERIC_DESTRUCTOR::*)()) &GENERIC_DESTRUCTOR::operator(), py::is_operator(), "None");


}
