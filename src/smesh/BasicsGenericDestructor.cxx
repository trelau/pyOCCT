/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>

#include <BasicsGenericDestructor.hxx>

PYBIND11_MODULE(BasicsGenericDestructor, mod) {

	// CLASSES
	py::class_<PROTECTED_DELETE, std::unique_ptr<PROTECTED_DELETE, py::nodelete>> cls_PROTECTED_DELETE(mod, "PROTECTED_DELETE", "The PROTECTED_DELETE base class provides a protected destructor. The only way to use PROTECTED_DELETE is inheritance: example: class LocalTraceBufferPool : public PROTECTED_DELETE Herited class destructor must stay protected. Normal use is: - create an instance of herited class on the heap (new), - use addObj(instance) to store the instance on the static list _objList, - delete instance with deleteInstance(instance)");
	cls_PROTECTED_DELETE.def(py::init<>());
	cls_PROTECTED_DELETE.def_static("deleteInstance_", (void (*)(PROTECTED_DELETE *)) &PROTECTED_DELETE::deleteInstance, "None", py::arg("anObject"));
	cls_PROTECTED_DELETE.def_static("addObj_", (void (*)(PROTECTED_DELETE *)) &PROTECTED_DELETE::addObj, "None", py::arg("anObject"));

	py::class_<GENERIC_DESTRUCTOR> cls_GENERIC_DESTRUCTOR(mod, "GENERIC_DESTRUCTOR", "The GENERIC_DESTRUCTOR abstract class describes the comportement of any destruction object. This type is used to create a list of miscellaneous destruction objects.");
	cls_GENERIC_DESTRUCTOR.def_static("Add_", (const int (*)(GENERIC_DESTRUCTOR &)) &GENERIC_DESTRUCTOR::Add, "None", py::arg("anObject"));
	cls_GENERIC_DESTRUCTOR.def("__call__", (void (GENERIC_DESTRUCTOR::*)()) &GENERIC_DESTRUCTOR::operator(), py::is_operator(), "None");


}
