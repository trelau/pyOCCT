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
#include <NCollection_Array2.hxx>
#include <Standard_Handle.hxx>
#include <StdObjMgt_Persistent.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <StdLPersistent_HArray2.hxx>
#include <Standard_Type.hxx>

void bind_StdLPersistent_HArray2OfPersistent(py::module &mod){

py::class_<StdLPersistent_HArray2OfPersistent, opencascade::handle<StdLPersistent_HArray2OfPersistent>, Standard_Transient> cls_StdLPersistent_HArray2OfPersistent(mod, "StdLPersistent_HArray2OfPersistent", "None", py::multiple_inheritance());

// Constructors
cls_StdLPersistent_HArray2OfPersistent.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
cls_StdLPersistent_HArray2OfPersistent.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const NCollection_Array2<opencascade::handle<StdObjMgt_Persistent> >::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
cls_StdLPersistent_HArray2OfPersistent.def(py::init<const NCollection_Array2<opencascade::handle<StdObjMgt_Persistent> > &>(), py::arg("theOther"));

// Fields

// Methods
// cls_StdLPersistent_HArray2OfPersistent.def_static("operator new_", (void * (*)(size_t)) &StdLPersistent_HArray2OfPersistent::operator new, "None", py::arg("theSize"));
// cls_StdLPersistent_HArray2OfPersistent.def_static("operator delete_", (void (*)(void *)) &StdLPersistent_HArray2OfPersistent::operator delete, "None", py::arg("theAddress"));
// cls_StdLPersistent_HArray2OfPersistent.def_static("operator new[]_", (void * (*)(size_t)) &StdLPersistent_HArray2OfPersistent::operator new[], "None", py::arg("theSize"));
// cls_StdLPersistent_HArray2OfPersistent.def_static("operator delete[]_", (void (*)(void *)) &StdLPersistent_HArray2OfPersistent::operator delete[], "None", py::arg("theAddress"));
// cls_StdLPersistent_HArray2OfPersistent.def_static("operator new_", (void * (*)(size_t, void *)) &StdLPersistent_HArray2OfPersistent::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StdLPersistent_HArray2OfPersistent.def_static("operator delete_", (void (*)(void *, void *)) &StdLPersistent_HArray2OfPersistent::operator delete, "None", py::arg(""), py::arg(""));
// cls_StdLPersistent_HArray2OfPersistent.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StdLPersistent_HArray2OfPersistent::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StdLPersistent_HArray2OfPersistent.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StdLPersistent_HArray2OfPersistent::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StdLPersistent_HArray2OfPersistent.def("Array2", (const NCollection_Array2<opencascade::handle<StdObjMgt_Persistent> > & (StdLPersistent_HArray2OfPersistent::*)() const) &StdLPersistent_HArray2OfPersistent::Array2, "None");
cls_StdLPersistent_HArray2OfPersistent.def("ChangeArray2", (NCollection_Array2<opencascade::handle<StdObjMgt_Persistent> > & (StdLPersistent_HArray2OfPersistent::*)()) &StdLPersistent_HArray2OfPersistent::ChangeArray2, "None");
cls_StdLPersistent_HArray2OfPersistent.def_static("get_type_name_", (const char * (*)()) &StdLPersistent_HArray2OfPersistent::get_type_name, "None");
cls_StdLPersistent_HArray2OfPersistent.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdLPersistent_HArray2OfPersistent::get_type_descriptor, "None");
cls_StdLPersistent_HArray2OfPersistent.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdLPersistent_HArray2OfPersistent::*)() const) &StdLPersistent_HArray2OfPersistent::DynamicType, "None");

// Enums

}