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
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <ShapeAnalysis_HSequenceOfFreeBounds.hxx>
#include <ShapeAnalysis_FreeBoundData.hxx>
#include <TopoDS_Wire.hxx>
#include <ShapeAnalysis_FreeBoundsProperties.hxx>

void bind_ShapeAnalysis_FreeBoundsProperties(py::module &mod){

py::class_<ShapeAnalysis_FreeBoundsProperties> cls_ShapeAnalysis_FreeBoundsProperties(mod, "ShapeAnalysis_FreeBoundsProperties", "This class is intended to calculate shape free bounds properties. This class provides the following functionalities: - calculates area of the contour, - calculates perimeter of the contour, - calculates ratio of average length to average width of the contour, - estimates average width of contour, - finds the notches (narrow 'V'-like sub-contour) on the contour.");

// Constructors
cls_ShapeAnalysis_FreeBoundsProperties.def(py::init<>());
cls_ShapeAnalysis_FreeBoundsProperties.def(py::init<const TopoDS_Shape &, const Standard_Real>(), py::arg("shape"), py::arg("tolerance"));
cls_ShapeAnalysis_FreeBoundsProperties.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Boolean>(), py::arg("shape"), py::arg("tolerance"), py::arg("splitclosed"));
cls_ShapeAnalysis_FreeBoundsProperties.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Boolean, const Standard_Boolean>(), py::arg("shape"), py::arg("tolerance"), py::arg("splitclosed"), py::arg("splitopen"));
cls_ShapeAnalysis_FreeBoundsProperties.def(py::init<const TopoDS_Shape &>(), py::arg("shape"));
cls_ShapeAnalysis_FreeBoundsProperties.def(py::init<const TopoDS_Shape &, const Standard_Boolean>(), py::arg("shape"), py::arg("splitclosed"));
cls_ShapeAnalysis_FreeBoundsProperties.def(py::init<const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean>(), py::arg("shape"), py::arg("splitclosed"), py::arg("splitopen"));

// Fields

// Methods
// cls_ShapeAnalysis_FreeBoundsProperties.def_static("operator new_", (void * (*)(size_t)) &ShapeAnalysis_FreeBoundsProperties::operator new, "None", py::arg("theSize"));
// cls_ShapeAnalysis_FreeBoundsProperties.def_static("operator delete_", (void (*)(void *)) &ShapeAnalysis_FreeBoundsProperties::operator delete, "None", py::arg("theAddress"));
// cls_ShapeAnalysis_FreeBoundsProperties.def_static("operator new[]_", (void * (*)(size_t)) &ShapeAnalysis_FreeBoundsProperties::operator new[], "None", py::arg("theSize"));
// cls_ShapeAnalysis_FreeBoundsProperties.def_static("operator delete[]_", (void (*)(void *)) &ShapeAnalysis_FreeBoundsProperties::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeAnalysis_FreeBoundsProperties.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeAnalysis_FreeBoundsProperties::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeAnalysis_FreeBoundsProperties.def_static("operator delete_", (void (*)(void *, void *)) &ShapeAnalysis_FreeBoundsProperties::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeAnalysis_FreeBoundsProperties.def("Init", [](ShapeAnalysis_FreeBoundsProperties &self, const TopoDS_Shape & a0, const Standard_Real a1) -> void { return self.Init(a0, a1); });
cls_ShapeAnalysis_FreeBoundsProperties.def("Init", [](ShapeAnalysis_FreeBoundsProperties &self, const TopoDS_Shape & a0, const Standard_Real a1, const Standard_Boolean a2) -> void { return self.Init(a0, a1, a2); });
cls_ShapeAnalysis_FreeBoundsProperties.def("Init", (void (ShapeAnalysis_FreeBoundsProperties::*)(const TopoDS_Shape &, const Standard_Real, const Standard_Boolean, const Standard_Boolean)) &ShapeAnalysis_FreeBoundsProperties::Init, "Initializes the object with given parameters. <shape> should be a compound of faces.", py::arg("shape"), py::arg("tolerance"), py::arg("splitclosed"), py::arg("splitopen"));
cls_ShapeAnalysis_FreeBoundsProperties.def("Init", [](ShapeAnalysis_FreeBoundsProperties &self, const TopoDS_Shape & a0) -> void { return self.Init(a0); });
cls_ShapeAnalysis_FreeBoundsProperties.def("Init", [](ShapeAnalysis_FreeBoundsProperties &self, const TopoDS_Shape & a0, const Standard_Boolean a1) -> void { return self.Init(a0, a1); });
cls_ShapeAnalysis_FreeBoundsProperties.def("Init", (void (ShapeAnalysis_FreeBoundsProperties::*)(const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean)) &ShapeAnalysis_FreeBoundsProperties::Init, "Initializes the object with given parameters. <shape> should be a compound of shells.", py::arg("shape"), py::arg("splitclosed"), py::arg("splitopen"));
cls_ShapeAnalysis_FreeBoundsProperties.def("Perform", (Standard_Boolean (ShapeAnalysis_FreeBoundsProperties::*)()) &ShapeAnalysis_FreeBoundsProperties::Perform, "Builds and analyzes free bounds of the shape. First calls ShapeAnalysis_FreeBounds for building free bounds. Then on each free bound computes its properties: - area of the contour, - perimeter of the contour, - ratio of average length to average width of the contour, - average width of contour, - notches on the contour and for each notch - maximum width of the notch.");
cls_ShapeAnalysis_FreeBoundsProperties.def("IsLoaded", (Standard_Boolean (ShapeAnalysis_FreeBoundsProperties::*)() const) &ShapeAnalysis_FreeBoundsProperties::IsLoaded, "Returns True if shape is loaded");
cls_ShapeAnalysis_FreeBoundsProperties.def("Shape", (TopoDS_Shape (ShapeAnalysis_FreeBoundsProperties::*)() const) &ShapeAnalysis_FreeBoundsProperties::Shape, "Returns shape");
cls_ShapeAnalysis_FreeBoundsProperties.def("Tolerance", (Standard_Real (ShapeAnalysis_FreeBoundsProperties::*)() const) &ShapeAnalysis_FreeBoundsProperties::Tolerance, "Returns tolerance");
cls_ShapeAnalysis_FreeBoundsProperties.def("NbFreeBounds", (Standard_Integer (ShapeAnalysis_FreeBoundsProperties::*)() const) &ShapeAnalysis_FreeBoundsProperties::NbFreeBounds, "Returns number of free bounds");
cls_ShapeAnalysis_FreeBoundsProperties.def("NbClosedFreeBounds", (Standard_Integer (ShapeAnalysis_FreeBoundsProperties::*)() const) &ShapeAnalysis_FreeBoundsProperties::NbClosedFreeBounds, "Returns number of closed free bounds");
cls_ShapeAnalysis_FreeBoundsProperties.def("NbOpenFreeBounds", (Standard_Integer (ShapeAnalysis_FreeBoundsProperties::*)() const) &ShapeAnalysis_FreeBoundsProperties::NbOpenFreeBounds, "Returns number of open free bounds");
cls_ShapeAnalysis_FreeBoundsProperties.def("ClosedFreeBounds", (opencascade::handle<ShapeAnalysis_HSequenceOfFreeBounds> (ShapeAnalysis_FreeBoundsProperties::*)() const) &ShapeAnalysis_FreeBoundsProperties::ClosedFreeBounds, "Returns all closed free bounds");
cls_ShapeAnalysis_FreeBoundsProperties.def("OpenFreeBounds", (opencascade::handle<ShapeAnalysis_HSequenceOfFreeBounds> (ShapeAnalysis_FreeBoundsProperties::*)() const) &ShapeAnalysis_FreeBoundsProperties::OpenFreeBounds, "Returns all open free bounds");
cls_ShapeAnalysis_FreeBoundsProperties.def("ClosedFreeBound", (opencascade::handle<ShapeAnalysis_FreeBoundData> (ShapeAnalysis_FreeBoundsProperties::*)(const Standard_Integer) const) &ShapeAnalysis_FreeBoundsProperties::ClosedFreeBound, "Returns properties of closed free bound specified by its rank number", py::arg("index"));
cls_ShapeAnalysis_FreeBoundsProperties.def("OpenFreeBound", (opencascade::handle<ShapeAnalysis_FreeBoundData> (ShapeAnalysis_FreeBoundsProperties::*)(const Standard_Integer) const) &ShapeAnalysis_FreeBoundsProperties::OpenFreeBound, "Returns properties of open free bound specified by its rank number", py::arg("index"));
cls_ShapeAnalysis_FreeBoundsProperties.def("DispatchBounds", (Standard_Boolean (ShapeAnalysis_FreeBoundsProperties::*)()) &ShapeAnalysis_FreeBoundsProperties::DispatchBounds, "None");
cls_ShapeAnalysis_FreeBoundsProperties.def("CheckContours", [](ShapeAnalysis_FreeBoundsProperties &self) -> Standard_Boolean { return self.CheckContours(); });
cls_ShapeAnalysis_FreeBoundsProperties.def("CheckContours", (Standard_Boolean (ShapeAnalysis_FreeBoundsProperties::*)(const Standard_Real)) &ShapeAnalysis_FreeBoundsProperties::CheckContours, "None", py::arg("prec"));
cls_ShapeAnalysis_FreeBoundsProperties.def("CheckNotches", [](ShapeAnalysis_FreeBoundsProperties &self) -> Standard_Boolean { return self.CheckNotches(); });
cls_ShapeAnalysis_FreeBoundsProperties.def("CheckNotches", (Standard_Boolean (ShapeAnalysis_FreeBoundsProperties::*)(const Standard_Real)) &ShapeAnalysis_FreeBoundsProperties::CheckNotches, "None", py::arg("prec"));
cls_ShapeAnalysis_FreeBoundsProperties.def("CheckNotches", [](ShapeAnalysis_FreeBoundsProperties &self, opencascade::handle<ShapeAnalysis_FreeBoundData> & a0) -> Standard_Boolean { return self.CheckNotches(a0); });
cls_ShapeAnalysis_FreeBoundsProperties.def("CheckNotches", (Standard_Boolean (ShapeAnalysis_FreeBoundsProperties::*)(opencascade::handle<ShapeAnalysis_FreeBoundData> &, const Standard_Real)) &ShapeAnalysis_FreeBoundsProperties::CheckNotches, "None", py::arg("fbData"), py::arg("prec"));
cls_ShapeAnalysis_FreeBoundsProperties.def("CheckNotches", [](ShapeAnalysis_FreeBoundsProperties &self, const TopoDS_Wire & freebound, const Standard_Integer num, TopoDS_Wire & notch, Standard_Real & distMax, const Standard_Real prec){ Standard_Boolean rv = self.CheckNotches(freebound, num, notch, distMax, prec); return std::tuple<Standard_Boolean, Standard_Real &>(rv, distMax); }, "None", py::arg("freebound"), py::arg("num"), py::arg("notch"), py::arg("distMax"), py::arg("prec"));
cls_ShapeAnalysis_FreeBoundsProperties.def("FillProperties", [](ShapeAnalysis_FreeBoundsProperties &self, opencascade::handle<ShapeAnalysis_FreeBoundData> & a0) -> Standard_Boolean { return self.FillProperties(a0); });
cls_ShapeAnalysis_FreeBoundsProperties.def("FillProperties", (Standard_Boolean (ShapeAnalysis_FreeBoundsProperties::*)(opencascade::handle<ShapeAnalysis_FreeBoundData> &, const Standard_Real)) &ShapeAnalysis_FreeBoundsProperties::FillProperties, "None", py::arg("fbData"), py::arg("prec"));

// Enums

}