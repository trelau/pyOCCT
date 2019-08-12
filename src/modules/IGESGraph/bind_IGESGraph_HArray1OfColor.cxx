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
#include <IGESGraph_Array1OfColor.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <IGESGraph_HArray1OfColor.hxx>
#include <Standard_Type.hxx>

void bind_IGESGraph_HArray1OfColor(py::module &mod){

py::class_<IGESGraph_HArray1OfColor, opencascade::handle<IGESGraph_HArray1OfColor>, Standard_Transient> cls_IGESGraph_HArray1OfColor(mod, "IGESGraph_HArray1OfColor", "None", py::multiple_inheritance());

// Constructors
cls_IGESGraph_HArray1OfColor.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_IGESGraph_HArray1OfColor.def(py::init<const Standard_Integer, const Standard_Integer, const IGESGraph_Array1OfColor::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_IGESGraph_HArray1OfColor.def(py::init<const IGESGraph_Array1OfColor &>(), py::arg("theOther"));

// Fields

// Methods
// cls_IGESGraph_HArray1OfColor.def_static("operator new_", (void * (*)(size_t)) &IGESGraph_HArray1OfColor::operator new, "None", py::arg("theSize"));
// cls_IGESGraph_HArray1OfColor.def_static("operator delete_", (void (*)(void *)) &IGESGraph_HArray1OfColor::operator delete, "None", py::arg("theAddress"));
// cls_IGESGraph_HArray1OfColor.def_static("operator new[]_", (void * (*)(size_t)) &IGESGraph_HArray1OfColor::operator new[], "None", py::arg("theSize"));
// cls_IGESGraph_HArray1OfColor.def_static("operator delete[]_", (void (*)(void *)) &IGESGraph_HArray1OfColor::operator delete[], "None", py::arg("theAddress"));
// cls_IGESGraph_HArray1OfColor.def_static("operator new_", (void * (*)(size_t, void *)) &IGESGraph_HArray1OfColor::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESGraph_HArray1OfColor.def_static("operator delete_", (void (*)(void *, void *)) &IGESGraph_HArray1OfColor::operator delete, "None", py::arg(""), py::arg(""));
// cls_IGESGraph_HArray1OfColor.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &IGESGraph_HArray1OfColor::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_IGESGraph_HArray1OfColor.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &IGESGraph_HArray1OfColor::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_IGESGraph_HArray1OfColor.def("Array1", (const IGESGraph_Array1OfColor & (IGESGraph_HArray1OfColor::*)() const) &IGESGraph_HArray1OfColor::Array1, "None");
cls_IGESGraph_HArray1OfColor.def("ChangeArray1", (IGESGraph_Array1OfColor & (IGESGraph_HArray1OfColor::*)()) &IGESGraph_HArray1OfColor::ChangeArray1, "None");
cls_IGESGraph_HArray1OfColor.def_static("get_type_name_", (const char * (*)()) &IGESGraph_HArray1OfColor::get_type_name, "None");
cls_IGESGraph_HArray1OfColor.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGraph_HArray1OfColor::get_type_descriptor, "None");
cls_IGESGraph_HArray1OfColor.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGraph_HArray1OfColor::*)() const) &IGESGraph_HArray1OfColor::DynamicType, "None");

// Enums

}