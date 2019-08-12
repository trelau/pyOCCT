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
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <Standard_Handle.hxx>
#include <TopTools_HSequenceOfShape.hxx>
#include <ShapeAnalysis_ShapeTolerance.hxx>

void bind_ShapeAnalysis_ShapeTolerance(py::module &mod){

py::class_<ShapeAnalysis_ShapeTolerance, std::unique_ptr<ShapeAnalysis_ShapeTolerance, Deleter<ShapeAnalysis_ShapeTolerance>>> cls_ShapeAnalysis_ShapeTolerance(mod, "ShapeAnalysis_ShapeTolerance", "Tool for computing shape tolerances (minimal, maximal, average), finding shape with tolerance matching given criteria, setting or limitating tolerances.");

// Constructors
cls_ShapeAnalysis_ShapeTolerance.def(py::init<>());

// Fields

// Methods
// cls_ShapeAnalysis_ShapeTolerance.def_static("operator new_", (void * (*)(size_t)) &ShapeAnalysis_ShapeTolerance::operator new, "None", py::arg("theSize"));
// cls_ShapeAnalysis_ShapeTolerance.def_static("operator delete_", (void (*)(void *)) &ShapeAnalysis_ShapeTolerance::operator delete, "None", py::arg("theAddress"));
// cls_ShapeAnalysis_ShapeTolerance.def_static("operator new[]_", (void * (*)(size_t)) &ShapeAnalysis_ShapeTolerance::operator new[], "None", py::arg("theSize"));
// cls_ShapeAnalysis_ShapeTolerance.def_static("operator delete[]_", (void (*)(void *)) &ShapeAnalysis_ShapeTolerance::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeAnalysis_ShapeTolerance.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeAnalysis_ShapeTolerance::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeAnalysis_ShapeTolerance.def_static("operator delete_", (void (*)(void *, void *)) &ShapeAnalysis_ShapeTolerance::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeAnalysis_ShapeTolerance.def("Tolerance", [](ShapeAnalysis_ShapeTolerance &self, const TopoDS_Shape & a0, const Standard_Integer a1) -> Standard_Real { return self.Tolerance(a0, a1); });
cls_ShapeAnalysis_ShapeTolerance.def("Tolerance", (Standard_Real (ShapeAnalysis_ShapeTolerance::*)(const TopoDS_Shape &, const Standard_Integer, const TopAbs_ShapeEnum)) &ShapeAnalysis_ShapeTolerance::Tolerance, "Determines a tolerance from the ones stored in a shape Remark : calls InitTolerance and AddTolerance, hence, can be used to start a series for cumulating tolerance <mode> = 0 : returns the average value between sub-shapes, <mode> > 0 : returns the maximal found, <mode> < 0 : returns the minimal found. <type> defines what kinds of sub-shapes to consider: SHAPE (default) : all : VERTEX, EDGE, FACE, VERTEX : only vertices, EDGE : only edges, FACE : only faces, SHELL : combined SHELL + FACE, for each face (and containing shell), also checks EDGE and VERTEX", py::arg("shape"), py::arg("mode"), py::arg("type"));
cls_ShapeAnalysis_ShapeTolerance.def("OverTolerance", [](ShapeAnalysis_ShapeTolerance &self, const TopoDS_Shape & a0, const Standard_Real a1) -> opencascade::handle<TopTools_HSequenceOfShape> { return self.OverTolerance(a0, a1); });
cls_ShapeAnalysis_ShapeTolerance.def("OverTolerance", (opencascade::handle<TopTools_HSequenceOfShape> (ShapeAnalysis_ShapeTolerance::*)(const TopoDS_Shape &, const Standard_Real, const TopAbs_ShapeEnum) const) &ShapeAnalysis_ShapeTolerance::OverTolerance, "Determines which shapes have a tolerance over the given value <type> is interpreted as in the method Tolerance", py::arg("shape"), py::arg("value"), py::arg("type"));
cls_ShapeAnalysis_ShapeTolerance.def("InTolerance", [](ShapeAnalysis_ShapeTolerance &self, const TopoDS_Shape & a0, const Standard_Real a1, const Standard_Real a2) -> opencascade::handle<TopTools_HSequenceOfShape> { return self.InTolerance(a0, a1, a2); });
cls_ShapeAnalysis_ShapeTolerance.def("InTolerance", (opencascade::handle<TopTools_HSequenceOfShape> (ShapeAnalysis_ShapeTolerance::*)(const TopoDS_Shape &, const Standard_Real, const Standard_Real, const TopAbs_ShapeEnum) const) &ShapeAnalysis_ShapeTolerance::InTolerance, "Determines which shapes have a tolerance within a given interval <type> is interpreted as in the method Tolerance", py::arg("shape"), py::arg("valmin"), py::arg("valmax"), py::arg("type"));
cls_ShapeAnalysis_ShapeTolerance.def("InitTolerance", (void (ShapeAnalysis_ShapeTolerance::*)()) &ShapeAnalysis_ShapeTolerance::InitTolerance, "Initializes computation of cumulated tolerance");
cls_ShapeAnalysis_ShapeTolerance.def("AddTolerance", [](ShapeAnalysis_ShapeTolerance &self, const TopoDS_Shape & a0) -> void { return self.AddTolerance(a0); });
cls_ShapeAnalysis_ShapeTolerance.def("AddTolerance", (void (ShapeAnalysis_ShapeTolerance::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum)) &ShapeAnalysis_ShapeTolerance::AddTolerance, "Adds data on new Shape to compute Cumulated Tolerance (prepares three computations : maximal, average, minimal)", py::arg("shape"), py::arg("type"));
cls_ShapeAnalysis_ShapeTolerance.def("GlobalTolerance", (Standard_Real (ShapeAnalysis_ShapeTolerance::*)(const Standard_Integer) const) &ShapeAnalysis_ShapeTolerance::GlobalTolerance, "Returns the computed tolerance according to the <mode> <mode> = 0 : average <mode> > 0 : maximal <mode> < 0 : minimal", py::arg("mode"));

// Enums

}