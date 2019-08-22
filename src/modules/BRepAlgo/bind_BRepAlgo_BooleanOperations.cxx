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
#include <TopOpeBRepDS_HDataStructure.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopOpeBRepBuild_HBuilder.hxx>
#include <BRepAlgo_DSAccess.hxx>
#include <TopAbs_State.hxx>
#include <TopTools_MapOfShape.hxx>
#include <BRepAlgo_BooleanOperations.hxx>

void bind_BRepAlgo_BooleanOperations(py::module &mod){

py::class_<BRepAlgo_BooleanOperations> cls_BRepAlgo_BooleanOperations(mod, "BRepAlgo_BooleanOperations", "None");

// Constructors
cls_BRepAlgo_BooleanOperations.def(py::init<>());

// Fields

// Methods
// cls_BRepAlgo_BooleanOperations.def_static("operator new_", (void * (*)(size_t)) &BRepAlgo_BooleanOperations::operator new, "None", py::arg("theSize"));
// cls_BRepAlgo_BooleanOperations.def_static("operator delete_", (void (*)(void *)) &BRepAlgo_BooleanOperations::operator delete, "None", py::arg("theAddress"));
// cls_BRepAlgo_BooleanOperations.def_static("operator new[]_", (void * (*)(size_t)) &BRepAlgo_BooleanOperations::operator new[], "None", py::arg("theSize"));
// cls_BRepAlgo_BooleanOperations.def_static("operator delete[]_", (void (*)(void *)) &BRepAlgo_BooleanOperations::operator delete[], "None", py::arg("theAddress"));
// cls_BRepAlgo_BooleanOperations.def_static("operator new_", (void * (*)(size_t, void *)) &BRepAlgo_BooleanOperations::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepAlgo_BooleanOperations.def_static("operator delete_", (void (*)(void *, void *)) &BRepAlgo_BooleanOperations::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepAlgo_BooleanOperations.def("Shapes2d", (void (BRepAlgo_BooleanOperations::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepAlgo_BooleanOperations::Shapes2d, "S1 is a Shell with ALL faces supported by the SAME S2 is an Edge INCLUDED in that surface with pcurve. this avoids a time-consuming 3D operation, compared to Shapes.", py::arg("S1"), py::arg("S2"));
cls_BRepAlgo_BooleanOperations.def("Shapes", (void (BRepAlgo_BooleanOperations::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepAlgo_BooleanOperations::Shapes, "Defines the arguments.", py::arg("S1"), py::arg("S2"));
cls_BRepAlgo_BooleanOperations.def("SetApproxParameters", (void (BRepAlgo_BooleanOperations::*)(const Standard_Integer, const Standard_Real, const Standard_Real)) &BRepAlgo_BooleanOperations::SetApproxParameters, "Sets different parameters for the curve approximations : NbPntMax : Maximum number of points to be approximated at the same time in one curve. Tol3D, Tol2D : Tolerances to be reached by the approximation. RelativeTol : The given tolerances are relative.", py::arg("NbPntMax"), py::arg("Tol3D"), py::arg("Tol2D"));
cls_BRepAlgo_BooleanOperations.def("Define", (void (BRepAlgo_BooleanOperations::*)(const TopoDS_Shape &, const TopoDS_Shape &, opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &BRepAlgo_BooleanOperations::Define, "None", py::arg("S1"), py::arg("S2"), py::arg("HDS"));
cls_BRepAlgo_BooleanOperations.def("Common", (const TopoDS_Shape & (BRepAlgo_BooleanOperations::*)()) &BRepAlgo_BooleanOperations::Common, "returns the common part of the shapes.");
cls_BRepAlgo_BooleanOperations.def("Fus", (const TopoDS_Shape & (BRepAlgo_BooleanOperations::*)()) &BRepAlgo_BooleanOperations::Fus, "returns the fuse part of the shapes.");
cls_BRepAlgo_BooleanOperations.def("Cut", (const TopoDS_Shape & (BRepAlgo_BooleanOperations::*)()) &BRepAlgo_BooleanOperations::Cut, "returns the cut part of the shapes.");
cls_BRepAlgo_BooleanOperations.def("Section", (const TopoDS_Shape & (BRepAlgo_BooleanOperations::*)()) &BRepAlgo_BooleanOperations::Section, "returns the intersection of the shapes.");
cls_BRepAlgo_BooleanOperations.def("Shape", (const TopoDS_Shape & (BRepAlgo_BooleanOperations::*)()) &BRepAlgo_BooleanOperations::Shape, "returns the result of the boolean operation.");
cls_BRepAlgo_BooleanOperations.def("ShapeFrom", (const TopoDS_Shape & (BRepAlgo_BooleanOperations::*)(const TopoDS_Shape &)) &BRepAlgo_BooleanOperations::ShapeFrom, "Returns the shape(s) resulting of the boolean operation issued from the shape <S>.", py::arg("S"));
cls_BRepAlgo_BooleanOperations.def("Modified", (const TopTools_ListOfShape & (BRepAlgo_BooleanOperations::*)(const TopoDS_Shape &)) &BRepAlgo_BooleanOperations::Modified, "Returns the list of the descendant shapes of the shape <S>.", py::arg("S"));
cls_BRepAlgo_BooleanOperations.def("IsDeleted", (Standard_Boolean (BRepAlgo_BooleanOperations::*)(const TopoDS_Shape &)) &BRepAlgo_BooleanOperations::IsDeleted, "Returns the fact that the shape <S> has been deleted or not by the boolean operation.", py::arg("S"));
cls_BRepAlgo_BooleanOperations.def("DataStructure", (const opencascade::handle<TopOpeBRepDS_HDataStructure> & (BRepAlgo_BooleanOperations::*)() const) &BRepAlgo_BooleanOperations::DataStructure, "None");
cls_BRepAlgo_BooleanOperations.def("ChangeDataStructure", (opencascade::handle<TopOpeBRepDS_HDataStructure> & (BRepAlgo_BooleanOperations::*)()) &BRepAlgo_BooleanOperations::ChangeDataStructure, "None");
cls_BRepAlgo_BooleanOperations.def("Builder", (const opencascade::handle<TopOpeBRepBuild_HBuilder> & (BRepAlgo_BooleanOperations::*)() const) &BRepAlgo_BooleanOperations::Builder, "None");
cls_BRepAlgo_BooleanOperations.def("ChangeBuilder", (opencascade::handle<TopOpeBRepBuild_HBuilder> & (BRepAlgo_BooleanOperations::*)()) &BRepAlgo_BooleanOperations::ChangeBuilder, "None");
cls_BRepAlgo_BooleanOperations.def("DataStructureAccess", (BRepAlgo_DSAccess & (BRepAlgo_BooleanOperations::*)()) &BRepAlgo_BooleanOperations::DataStructureAccess, "returns the member myDSA. It is useful to then access the method GetSectionEdgeSet (wich is a member of DSAccess)");

// Enums

}