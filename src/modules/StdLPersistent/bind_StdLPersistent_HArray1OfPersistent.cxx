/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

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
#include <NCollection_Array1.hxx>
#include <Standard_Handle.hxx>
#include <StdObjMgt_Persistent.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <StdLPersistent_HArray1.hxx>
#include <Standard_Type.hxx>

void bind_StdLPersistent_HArray1OfPersistent(py::module &mod){

py::class_<StdLPersistent_HArray1OfPersistent, opencascade::handle<StdLPersistent_HArray1OfPersistent>, Standard_Transient> cls_StdLPersistent_HArray1OfPersistent(mod, "StdLPersistent_HArray1OfPersistent", "None", py::multiple_inheritance());

// Constructors
cls_StdLPersistent_HArray1OfPersistent.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_StdLPersistent_HArray1OfPersistent.def(py::init<const Standard_Integer, const Standard_Integer, const NCollection_Array1<opencascade::handle<StdObjMgt_Persistent> >::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_StdLPersistent_HArray1OfPersistent.def(py::init<const NCollection_Array1<opencascade::handle<StdObjMgt_Persistent> > &>(), py::arg("theOther"));

// Fields

// Methods
// cls_StdLPersistent_HArray1OfPersistent.def_static("operator new_", (void * (*)(size_t)) &StdLPersistent_HArray1OfPersistent::operator new, "None", py::arg("theSize"));
// cls_StdLPersistent_HArray1OfPersistent.def_static("operator delete_", (void (*)(void *)) &StdLPersistent_HArray1OfPersistent::operator delete, "None", py::arg("theAddress"));
// cls_StdLPersistent_HArray1OfPersistent.def_static("operator new[]_", (void * (*)(size_t)) &StdLPersistent_HArray1OfPersistent::operator new[], "None", py::arg("theSize"));
// cls_StdLPersistent_HArray1OfPersistent.def_static("operator delete[]_", (void (*)(void *)) &StdLPersistent_HArray1OfPersistent::operator delete[], "None", py::arg("theAddress"));
// cls_StdLPersistent_HArray1OfPersistent.def_static("operator new_", (void * (*)(size_t, void *)) &StdLPersistent_HArray1OfPersistent::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StdLPersistent_HArray1OfPersistent.def_static("operator delete_", (void (*)(void *, void *)) &StdLPersistent_HArray1OfPersistent::operator delete, "None", py::arg(""), py::arg(""));
// cls_StdLPersistent_HArray1OfPersistent.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StdLPersistent_HArray1OfPersistent::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StdLPersistent_HArray1OfPersistent.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StdLPersistent_HArray1OfPersistent::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StdLPersistent_HArray1OfPersistent.def("Array1", (const NCollection_Array1<opencascade::handle<StdObjMgt_Persistent> > & (StdLPersistent_HArray1OfPersistent::*)() const) &StdLPersistent_HArray1OfPersistent::Array1, "None");
cls_StdLPersistent_HArray1OfPersistent.def("ChangeArray1", (NCollection_Array1<opencascade::handle<StdObjMgt_Persistent> > & (StdLPersistent_HArray1OfPersistent::*)()) &StdLPersistent_HArray1OfPersistent::ChangeArray1, "None");
cls_StdLPersistent_HArray1OfPersistent.def_static("get_type_name_", (const char * (*)()) &StdLPersistent_HArray1OfPersistent::get_type_name, "None");
cls_StdLPersistent_HArray1OfPersistent.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdLPersistent_HArray1OfPersistent::get_type_descriptor, "None");
cls_StdLPersistent_HArray1OfPersistent.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdLPersistent_HArray1OfPersistent::*)() const) &StdLPersistent_HArray1OfPersistent::DynamicType, "None");

// Enums

}