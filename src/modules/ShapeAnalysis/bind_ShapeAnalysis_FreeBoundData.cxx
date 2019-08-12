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
#include <Standard_Transient.hxx>
#include <TopoDS_Wire.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TopTools_HSequenceOfShape.hxx>
#include <ShapeAnalysis_FreeBoundData.hxx>
#include <Standard_Type.hxx>
#include <TopTools_DataMapOfShapeReal.hxx>

void bind_ShapeAnalysis_FreeBoundData(py::module &mod){

py::class_<ShapeAnalysis_FreeBoundData, opencascade::handle<ShapeAnalysis_FreeBoundData>, Standard_Transient> cls_ShapeAnalysis_FreeBoundData(mod, "ShapeAnalysis_FreeBoundData", "This class is intended to represent free bound and to store its properties.");

// Constructors
cls_ShapeAnalysis_FreeBoundData.def(py::init<>());
cls_ShapeAnalysis_FreeBoundData.def(py::init<const TopoDS_Wire &>(), py::arg("freebound"));

// Fields

// Methods
cls_ShapeAnalysis_FreeBoundData.def("Clear", (void (ShapeAnalysis_FreeBoundData::*)()) &ShapeAnalysis_FreeBoundData::Clear, "Clears all properties of the contour. Contour bound itself is not cleared.");
cls_ShapeAnalysis_FreeBoundData.def("SetFreeBound", (void (ShapeAnalysis_FreeBoundData::*)(const TopoDS_Wire &)) &ShapeAnalysis_FreeBoundData::SetFreeBound, "Sets contour", py::arg("freebound"));
cls_ShapeAnalysis_FreeBoundData.def("SetArea", (void (ShapeAnalysis_FreeBoundData::*)(const Standard_Real)) &ShapeAnalysis_FreeBoundData::SetArea, "Sets area of the contour", py::arg("area"));
cls_ShapeAnalysis_FreeBoundData.def("SetPerimeter", (void (ShapeAnalysis_FreeBoundData::*)(const Standard_Real)) &ShapeAnalysis_FreeBoundData::SetPerimeter, "Sets perimeter of the contour", py::arg("perimeter"));
cls_ShapeAnalysis_FreeBoundData.def("SetRatio", (void (ShapeAnalysis_FreeBoundData::*)(const Standard_Real)) &ShapeAnalysis_FreeBoundData::SetRatio, "Sets ratio of average length to average width of the contour", py::arg("ratio"));
cls_ShapeAnalysis_FreeBoundData.def("SetWidth", (void (ShapeAnalysis_FreeBoundData::*)(const Standard_Real)) &ShapeAnalysis_FreeBoundData::SetWidth, "Sets average width of the contour", py::arg("width"));
cls_ShapeAnalysis_FreeBoundData.def("AddNotch", (void (ShapeAnalysis_FreeBoundData::*)(const TopoDS_Wire &, const Standard_Real)) &ShapeAnalysis_FreeBoundData::AddNotch, "Adds notch on the contour with its maximum width", py::arg("notch"), py::arg("width"));
cls_ShapeAnalysis_FreeBoundData.def("FreeBound", (TopoDS_Wire (ShapeAnalysis_FreeBoundData::*)() const) &ShapeAnalysis_FreeBoundData::FreeBound, "Returns contour");
cls_ShapeAnalysis_FreeBoundData.def("Area", (Standard_Real (ShapeAnalysis_FreeBoundData::*)() const) &ShapeAnalysis_FreeBoundData::Area, "Returns area of the contour");
cls_ShapeAnalysis_FreeBoundData.def("Perimeter", (Standard_Real (ShapeAnalysis_FreeBoundData::*)() const) &ShapeAnalysis_FreeBoundData::Perimeter, "Returns perimeter of the contour");
cls_ShapeAnalysis_FreeBoundData.def("Ratio", (Standard_Real (ShapeAnalysis_FreeBoundData::*)() const) &ShapeAnalysis_FreeBoundData::Ratio, "Returns ratio of average length to average width of the contour");
cls_ShapeAnalysis_FreeBoundData.def("Width", (Standard_Real (ShapeAnalysis_FreeBoundData::*)() const) &ShapeAnalysis_FreeBoundData::Width, "Returns average width of the contour");
cls_ShapeAnalysis_FreeBoundData.def("NbNotches", (Standard_Integer (ShapeAnalysis_FreeBoundData::*)() const) &ShapeAnalysis_FreeBoundData::NbNotches, "Returns number of notches on the contour");
cls_ShapeAnalysis_FreeBoundData.def("Notches", (opencascade::handle<TopTools_HSequenceOfShape> (ShapeAnalysis_FreeBoundData::*)() const) &ShapeAnalysis_FreeBoundData::Notches, "Returns sequence of notches on the contour");
cls_ShapeAnalysis_FreeBoundData.def("Notch", (TopoDS_Wire (ShapeAnalysis_FreeBoundData::*)(const Standard_Integer) const) &ShapeAnalysis_FreeBoundData::Notch, "Returns notch on the contour", py::arg("index"));
cls_ShapeAnalysis_FreeBoundData.def("NotchWidth", (Standard_Real (ShapeAnalysis_FreeBoundData::*)(const Standard_Integer) const) &ShapeAnalysis_FreeBoundData::NotchWidth, "Returns maximum width of notch specified by its rank number on the contour", py::arg("index"));
cls_ShapeAnalysis_FreeBoundData.def("NotchWidth", (Standard_Real (ShapeAnalysis_FreeBoundData::*)(const TopoDS_Wire &) const) &ShapeAnalysis_FreeBoundData::NotchWidth, "Returns maximum width of notch specified as TopoDS_Wire on the contour", py::arg("notch"));
cls_ShapeAnalysis_FreeBoundData.def_static("get_type_name_", (const char * (*)()) &ShapeAnalysis_FreeBoundData::get_type_name, "None");
cls_ShapeAnalysis_FreeBoundData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeAnalysis_FreeBoundData::get_type_descriptor, "None");
cls_ShapeAnalysis_FreeBoundData.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeAnalysis_FreeBoundData::*)() const) &ShapeAnalysis_FreeBoundData::DynamicType, "None");

// Enums

}