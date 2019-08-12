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
#include <IGESDraw_Array1OfConnectPoint.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <IGESDraw_HArray1OfConnectPoint.hxx>
#include <Standard_Type.hxx>

void bind_IGESDraw_HArray1OfConnectPoint(py::module &mod){

py::class_<IGESDraw_HArray1OfConnectPoint, opencascade::handle<IGESDraw_HArray1OfConnectPoint>, Standard_Transient> cls_IGESDraw_HArray1OfConnectPoint(mod, "IGESDraw_HArray1OfConnectPoint", "None", py::multiple_inheritance());

// Constructors
cls_IGESDraw_HArray1OfConnectPoint.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_IGESDraw_HArray1OfConnectPoint.def(py::init<const Standard_Integer, const Standard_Integer, const IGESDraw_Array1OfConnectPoint::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_IGESDraw_HArray1OfConnectPoint.def(py::init<const IGESDraw_Array1OfConnectPoint &>(), py::arg("theOther"));

// Fields

// Methods
// cls_IGESDraw_HArray1OfConnectPoint.def_static("operator new_", (void * (*)(size_t)) &IGESDraw_HArray1OfConnectPoint::operator new, "None", py::arg("theSize"));
// cls_IGESDraw_HArray1OfConnectPoint.def_static("operator delete_", (void (*)(void *)) &IGESDraw_HArray1OfConnectPoint::operator delete, "None", py::arg("theAddress"));
// cls_IGESDraw_HArray1OfConnectPoint.def_static("operator new[]_", (void * (*)(size_t)) &IGESDraw_HArray1OfConnectPoint::operator new[], "None", py::arg("theSize"));
// cls_IGESDraw_HArray1OfConnectPoint.def_static("operator delete[]_", (void (*)(void *)) &IGESDraw_HArray1OfConnectPoint::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDraw_HArray1OfConnectPoint.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDraw_HArray1OfConnectPoint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDraw_HArray1OfConnectPoint.def_static("operator delete_", (void (*)(void *, void *)) &IGESDraw_HArray1OfConnectPoint::operator delete, "None", py::arg(""), py::arg(""));
// cls_IGESDraw_HArray1OfConnectPoint.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &IGESDraw_HArray1OfConnectPoint::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_IGESDraw_HArray1OfConnectPoint.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &IGESDraw_HArray1OfConnectPoint::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_IGESDraw_HArray1OfConnectPoint.def("Array1", (const IGESDraw_Array1OfConnectPoint & (IGESDraw_HArray1OfConnectPoint::*)() const) &IGESDraw_HArray1OfConnectPoint::Array1, "None");
cls_IGESDraw_HArray1OfConnectPoint.def("ChangeArray1", (IGESDraw_Array1OfConnectPoint & (IGESDraw_HArray1OfConnectPoint::*)()) &IGESDraw_HArray1OfConnectPoint::ChangeArray1, "None");
cls_IGESDraw_HArray1OfConnectPoint.def_static("get_type_name_", (const char * (*)()) &IGESDraw_HArray1OfConnectPoint::get_type_name, "None");
cls_IGESDraw_HArray1OfConnectPoint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDraw_HArray1OfConnectPoint::get_type_descriptor, "None");
cls_IGESDraw_HArray1OfConnectPoint.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDraw_HArray1OfConnectPoint::*)() const) &IGESDraw_HArray1OfConnectPoint::DynamicType, "None");

// Enums

}