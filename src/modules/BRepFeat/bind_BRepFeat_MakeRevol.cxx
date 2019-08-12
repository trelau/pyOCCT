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
#include <BRepFeat_Form.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Face.hxx>
#include <gp_Ax1.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Edge.hxx>
#include <TColGeom_SequenceOfCurve.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <BRepFeat_StatusError.hxx>
#include <BRepFeat_MakeRevol.hxx>

void bind_BRepFeat_MakeRevol(py::module &mod){

py::class_<BRepFeat_MakeRevol, std::unique_ptr<BRepFeat_MakeRevol, Deleter<BRepFeat_MakeRevol>>, BRepFeat_Form> cls_BRepFeat_MakeRevol(mod, "BRepFeat_MakeRevol", "Describes functions to build revolved shells from basis shapes.");

// Constructors
cls_BRepFeat_MakeRevol.def(py::init<>());
cls_BRepFeat_MakeRevol.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Face &, const gp_Ax1 &, const Standard_Integer, const Standard_Boolean>(), py::arg("Sbase"), py::arg("Pbase"), py::arg("Skface"), py::arg("Axis"), py::arg("Fuse"), py::arg("Modify"));

// Fields

// Methods
// cls_BRepFeat_MakeRevol.def_static("operator new_", (void * (*)(size_t)) &BRepFeat_MakeRevol::operator new, "None", py::arg("theSize"));
// cls_BRepFeat_MakeRevol.def_static("operator delete_", (void (*)(void *)) &BRepFeat_MakeRevol::operator delete, "None", py::arg("theAddress"));
// cls_BRepFeat_MakeRevol.def_static("operator new[]_", (void * (*)(size_t)) &BRepFeat_MakeRevol::operator new[], "None", py::arg("theSize"));
// cls_BRepFeat_MakeRevol.def_static("operator delete[]_", (void (*)(void *)) &BRepFeat_MakeRevol::operator delete[], "None", py::arg("theAddress"));
// cls_BRepFeat_MakeRevol.def_static("operator new_", (void * (*)(size_t, void *)) &BRepFeat_MakeRevol::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepFeat_MakeRevol.def_static("operator delete_", (void (*)(void *, void *)) &BRepFeat_MakeRevol::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepFeat_MakeRevol.def("Init", (void (BRepFeat_MakeRevol::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Face &, const gp_Ax1 &, const Standard_Integer, const Standard_Boolean)) &BRepFeat_MakeRevol::Init, "None", py::arg("Sbase"), py::arg("Pbase"), py::arg("Skface"), py::arg("Axis"), py::arg("Fuse"), py::arg("Modify"));
cls_BRepFeat_MakeRevol.def("Add", (void (BRepFeat_MakeRevol::*)(const TopoDS_Edge &, const TopoDS_Face &)) &BRepFeat_MakeRevol::Add, "Indicates that the edge <E> will slide on the face <OnFace>. Raises ConstructionError if the face does not belong to the basis shape, or the edge to the prismed shape.", py::arg("E"), py::arg("OnFace"));
cls_BRepFeat_MakeRevol.def("Perform", (void (BRepFeat_MakeRevol::*)(const Standard_Real)) &BRepFeat_MakeRevol::Perform, "None", py::arg("Angle"));
cls_BRepFeat_MakeRevol.def("Perform", (void (BRepFeat_MakeRevol::*)(const TopoDS_Shape &)) &BRepFeat_MakeRevol::Perform, "None", py::arg("Until"));
cls_BRepFeat_MakeRevol.def("Perform", (void (BRepFeat_MakeRevol::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepFeat_MakeRevol::Perform, "Reconstructs the feature topologically.", py::arg("From"), py::arg("Until"));
cls_BRepFeat_MakeRevol.def("PerformThruAll", (void (BRepFeat_MakeRevol::*)()) &BRepFeat_MakeRevol::PerformThruAll, "Builds an infinite shell. The infinite descendants will not be kept in the result.");
cls_BRepFeat_MakeRevol.def("PerformUntilAngle", (void (BRepFeat_MakeRevol::*)(const TopoDS_Shape &, const Standard_Real)) &BRepFeat_MakeRevol::PerformUntilAngle, "Assigns both a limiting shape, Until from TopoDS_Shape, and an angle, Angle at which to stop generation of the revolved shell feature.", py::arg("Until"), py::arg("Angle"));
cls_BRepFeat_MakeRevol.def("Curves", (void (BRepFeat_MakeRevol::*)(TColGeom_SequenceOfCurve &)) &BRepFeat_MakeRevol::Curves, "None", py::arg("S"));
cls_BRepFeat_MakeRevol.def("BarycCurve", (opencascade::handle<Geom_Curve> (BRepFeat_MakeRevol::*)()) &BRepFeat_MakeRevol::BarycCurve, "None");

// Enums

}