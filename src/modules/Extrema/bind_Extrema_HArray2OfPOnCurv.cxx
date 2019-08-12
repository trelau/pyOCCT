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
#include <Extrema_Array2OfPOnCurv.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array2.hxx>
#include <Extrema_HArray2OfPOnCurv.hxx>
#include <Standard_Type.hxx>

void bind_Extrema_HArray2OfPOnCurv(py::module &mod){

py::class_<Extrema_HArray2OfPOnCurv, opencascade::handle<Extrema_HArray2OfPOnCurv>, Standard_Transient> cls_Extrema_HArray2OfPOnCurv(mod, "Extrema_HArray2OfPOnCurv", "None", py::multiple_inheritance());

// Constructors
cls_Extrema_HArray2OfPOnCurv.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
cls_Extrema_HArray2OfPOnCurv.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Extrema_Array2OfPOnCurv::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
cls_Extrema_HArray2OfPOnCurv.def(py::init<const Extrema_Array2OfPOnCurv &>(), py::arg("theOther"));

// Fields

// Methods
// cls_Extrema_HArray2OfPOnCurv.def_static("operator new_", (void * (*)(size_t)) &Extrema_HArray2OfPOnCurv::operator new, "None", py::arg("theSize"));
// cls_Extrema_HArray2OfPOnCurv.def_static("operator delete_", (void (*)(void *)) &Extrema_HArray2OfPOnCurv::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_HArray2OfPOnCurv.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_HArray2OfPOnCurv::operator new[], "None", py::arg("theSize"));
// cls_Extrema_HArray2OfPOnCurv.def_static("operator delete[]_", (void (*)(void *)) &Extrema_HArray2OfPOnCurv::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_HArray2OfPOnCurv.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_HArray2OfPOnCurv::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_HArray2OfPOnCurv.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_HArray2OfPOnCurv::operator delete, "None", py::arg(""), py::arg(""));
// cls_Extrema_HArray2OfPOnCurv.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &Extrema_HArray2OfPOnCurv::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_Extrema_HArray2OfPOnCurv.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &Extrema_HArray2OfPOnCurv::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_Extrema_HArray2OfPOnCurv.def("Array2", (const Extrema_Array2OfPOnCurv & (Extrema_HArray2OfPOnCurv::*)() const) &Extrema_HArray2OfPOnCurv::Array2, "None");
cls_Extrema_HArray2OfPOnCurv.def("ChangeArray2", (Extrema_Array2OfPOnCurv & (Extrema_HArray2OfPOnCurv::*)()) &Extrema_HArray2OfPOnCurv::ChangeArray2, "None");
cls_Extrema_HArray2OfPOnCurv.def_static("get_type_name_", (const char * (*)()) &Extrema_HArray2OfPOnCurv::get_type_name, "None");
cls_Extrema_HArray2OfPOnCurv.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Extrema_HArray2OfPOnCurv::get_type_descriptor, "None");
cls_Extrema_HArray2OfPOnCurv.def("DynamicType", (const opencascade::handle<Standard_Type> & (Extrema_HArray2OfPOnCurv::*)() const) &Extrema_HArray2OfPOnCurv::DynamicType, "None");

// Enums

}