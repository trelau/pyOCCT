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
#include <TopoDS_Face.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Curve.hxx>
#include <TopoDS_Shape.hxx>
#include <TColGeom2d_SequenceOfCurve.hxx>
#include <TColStd_SequenceOfBoolean.hxx>
#include <TopoDS_Wire.hxx>
#include <MAT2d_SequenceOfSequenceOfCurve.hxx>
#include <TopTools_IndexedDataMapOfShapeShape.hxx>
#include <BRepMAT2d_Explorer.hxx>

void bind_BRepMAT2d_Explorer(py::module &mod){

py::class_<BRepMAT2d_Explorer, std::unique_ptr<BRepMAT2d_Explorer>> cls_BRepMAT2d_Explorer(mod, "BRepMAT2d_Explorer", "Construct an explorer from wires, face, set of curves from Geom2d to compute the bisecting Locus.");

// Constructors
cls_BRepMAT2d_Explorer.def(py::init<>());
cls_BRepMAT2d_Explorer.def(py::init<const TopoDS_Face &>(), py::arg("aFace"));

// Fields

// Methods
// cls_BRepMAT2d_Explorer.def_static("operator new_", (void * (*)(size_t)) &BRepMAT2d_Explorer::operator new, "None", py::arg("theSize"));
// cls_BRepMAT2d_Explorer.def_static("operator delete_", (void (*)(void *)) &BRepMAT2d_Explorer::operator delete, "None", py::arg("theAddress"));
// cls_BRepMAT2d_Explorer.def_static("operator new[]_", (void * (*)(size_t)) &BRepMAT2d_Explorer::operator new[], "None", py::arg("theSize"));
// cls_BRepMAT2d_Explorer.def_static("operator delete[]_", (void (*)(void *)) &BRepMAT2d_Explorer::operator delete[], "None", py::arg("theAddress"));
// cls_BRepMAT2d_Explorer.def_static("operator new_", (void * (*)(size_t, void *)) &BRepMAT2d_Explorer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepMAT2d_Explorer.def_static("operator delete_", (void (*)(void *, void *)) &BRepMAT2d_Explorer::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepMAT2d_Explorer.def("Clear", (void (BRepMAT2d_Explorer::*)()) &BRepMAT2d_Explorer::Clear, "Clear the contents of <me>.");
cls_BRepMAT2d_Explorer.def("Perform", (void (BRepMAT2d_Explorer::*)(const TopoDS_Face &)) &BRepMAT2d_Explorer::Perform, "None", py::arg("aFace"));
cls_BRepMAT2d_Explorer.def("NumberOfContours", (Standard_Integer (BRepMAT2d_Explorer::*)() const) &BRepMAT2d_Explorer::NumberOfContours, "Returns the Number of contours.");
cls_BRepMAT2d_Explorer.def("NumberOfCurves", (Standard_Integer (BRepMAT2d_Explorer::*)(const Standard_Integer) const) &BRepMAT2d_Explorer::NumberOfCurves, "Returns the Number of Curves in the Contour number <IndexContour>.", py::arg("IndexContour"));
cls_BRepMAT2d_Explorer.def("Init", (void (BRepMAT2d_Explorer::*)(const Standard_Integer)) &BRepMAT2d_Explorer::Init, "Initialisation of an Iterator on the curves of the Contour number <IndexContour>.", py::arg("IndexContour"));
cls_BRepMAT2d_Explorer.def("More", (Standard_Boolean (BRepMAT2d_Explorer::*)() const) &BRepMAT2d_Explorer::More, "Return False if there is no more curves on the Contour initialised by the method Init.");
cls_BRepMAT2d_Explorer.def("Next", (void (BRepMAT2d_Explorer::*)()) &BRepMAT2d_Explorer::Next, "Move to the next curve of the current Contour.");
cls_BRepMAT2d_Explorer.def("Value", (opencascade::handle<Geom2d_Curve> (BRepMAT2d_Explorer::*)() const) &BRepMAT2d_Explorer::Value, "Returns the current curve on the current Contour.");
cls_BRepMAT2d_Explorer.def("Shape", (TopoDS_Shape (BRepMAT2d_Explorer::*)() const) &BRepMAT2d_Explorer::Shape, "None");
cls_BRepMAT2d_Explorer.def("Contour", (const TColGeom2d_SequenceOfCurve & (BRepMAT2d_Explorer::*)(const Standard_Integer) const) &BRepMAT2d_Explorer::Contour, "None", py::arg("IndexContour"));
cls_BRepMAT2d_Explorer.def("IsModified", (Standard_Boolean (BRepMAT2d_Explorer::*)(const TopoDS_Shape &) const) &BRepMAT2d_Explorer::IsModified, "None", py::arg("aShape"));
cls_BRepMAT2d_Explorer.def("ModifiedShape", (TopoDS_Shape (BRepMAT2d_Explorer::*)(const TopoDS_Shape &) const) &BRepMAT2d_Explorer::ModifiedShape, "If the shape is not modified, returns the shape itself.", py::arg("aShape"));
cls_BRepMAT2d_Explorer.def("GetIsClosed", (const TColStd_SequenceOfBoolean & (BRepMAT2d_Explorer::*)() const) &BRepMAT2d_Explorer::GetIsClosed, "None");

// Enums

}