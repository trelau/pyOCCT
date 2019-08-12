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
#include <BRepOffset_ListOfInterval.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Vertex.hxx>
#include <BRepOffset_Type.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Compound.hxx>
#include <TopTools_MapOfShape.hxx>
#include <BRepOffset_DataMapOfShapeListOfInterval.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <BRepOffset_Analyse.hxx>

void bind_BRepOffset_Analyse(py::module &mod){

py::class_<BRepOffset_Analyse, std::unique_ptr<BRepOffset_Analyse, Deleter<BRepOffset_Analyse>>> cls_BRepOffset_Analyse(mod, "BRepOffset_Analyse", "Analyse of a shape consit to Find the part of edges convex concave tangent.");

// Constructors
cls_BRepOffset_Analyse.def(py::init<>());
cls_BRepOffset_Analyse.def(py::init<const TopoDS_Shape &, const Standard_Real>(), py::arg("S"), py::arg("Angle"));

// Fields

// Methods
// cls_BRepOffset_Analyse.def_static("operator new_", (void * (*)(size_t)) &BRepOffset_Analyse::operator new, "None", py::arg("theSize"));
// cls_BRepOffset_Analyse.def_static("operator delete_", (void (*)(void *)) &BRepOffset_Analyse::operator delete, "None", py::arg("theAddress"));
// cls_BRepOffset_Analyse.def_static("operator new[]_", (void * (*)(size_t)) &BRepOffset_Analyse::operator new[], "None", py::arg("theSize"));
// cls_BRepOffset_Analyse.def_static("operator delete[]_", (void (*)(void *)) &BRepOffset_Analyse::operator delete[], "None", py::arg("theAddress"));
// cls_BRepOffset_Analyse.def_static("operator new_", (void * (*)(size_t, void *)) &BRepOffset_Analyse::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepOffset_Analyse.def_static("operator delete_", (void (*)(void *, void *)) &BRepOffset_Analyse::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepOffset_Analyse.def("Perform", (void (BRepOffset_Analyse::*)(const TopoDS_Shape &, const Standard_Real)) &BRepOffset_Analyse::Perform, "None", py::arg("S"), py::arg("Angle"));
cls_BRepOffset_Analyse.def("IsDone", (Standard_Boolean (BRepOffset_Analyse::*)() const) &BRepOffset_Analyse::IsDone, "None");
cls_BRepOffset_Analyse.def("Clear", (void (BRepOffset_Analyse::*)()) &BRepOffset_Analyse::Clear, "None");
cls_BRepOffset_Analyse.def("Type", (const BRepOffset_ListOfInterval & (BRepOffset_Analyse::*)(const TopoDS_Edge &) const) &BRepOffset_Analyse::Type, "None", py::arg("E"));
cls_BRepOffset_Analyse.def("Edges", (void (BRepOffset_Analyse::*)(const TopoDS_Vertex &, const BRepOffset_Type, TopTools_ListOfShape &) const) &BRepOffset_Analyse::Edges, "Stores in <L> all the edges of Type <T> on the vertex <V>.", py::arg("V"), py::arg("T"), py::arg("L"));
cls_BRepOffset_Analyse.def("Edges", (void (BRepOffset_Analyse::*)(const TopoDS_Face &, const BRepOffset_Type, TopTools_ListOfShape &) const) &BRepOffset_Analyse::Edges, "Stores in <L> all the edges of Type <T> on the face <F>.", py::arg("F"), py::arg("T"), py::arg("L"));
cls_BRepOffset_Analyse.def("TangentEdges", (void (BRepOffset_Analyse::*)(const TopoDS_Edge &, const TopoDS_Vertex &, TopTools_ListOfShape &) const) &BRepOffset_Analyse::TangentEdges, "set in <Edges> all the Edges of <Shape> which are tangent to <Edge> at the vertex <Vertex>.", py::arg("Edge"), py::arg("Vertex"), py::arg("Edges"));
cls_BRepOffset_Analyse.def("HasAncestor", (Standard_Boolean (BRepOffset_Analyse::*)(const TopoDS_Shape &) const) &BRepOffset_Analyse::HasAncestor, "None", py::arg("S"));
cls_BRepOffset_Analyse.def("Ancestors", (const TopTools_ListOfShape & (BRepOffset_Analyse::*)(const TopoDS_Shape &) const) &BRepOffset_Analyse::Ancestors, "None", py::arg("S"));
cls_BRepOffset_Analyse.def("Explode", (void (BRepOffset_Analyse::*)(TopTools_ListOfShape &, const BRepOffset_Type) const) &BRepOffset_Analyse::Explode, "Explode in compounds of faces where all the connex edges are of type <Side>", py::arg("L"), py::arg("Type"));
cls_BRepOffset_Analyse.def("Explode", (void (BRepOffset_Analyse::*)(TopTools_ListOfShape &, const BRepOffset_Type, const BRepOffset_Type) const) &BRepOffset_Analyse::Explode, "Explode in compounds of faces where all the connex edges are of type <Side1> or <Side2>", py::arg("L"), py::arg("Type1"), py::arg("Type2"));
cls_BRepOffset_Analyse.def("AddFaces", (void (BRepOffset_Analyse::*)(const TopoDS_Face &, TopoDS_Compound &, TopTools_MapOfShape &, const BRepOffset_Type) const) &BRepOffset_Analyse::AddFaces, "Add in <CO> the faces of the shell containing <Face> where all the connex edges are of type <Side>.", py::arg("Face"), py::arg("Co"), py::arg("Map"), py::arg("Type"));
cls_BRepOffset_Analyse.def("AddFaces", (void (BRepOffset_Analyse::*)(const TopoDS_Face &, TopoDS_Compound &, TopTools_MapOfShape &, const BRepOffset_Type, const BRepOffset_Type) const) &BRepOffset_Analyse::AddFaces, "Add in <CO> the faces of the shell containing <Face> where all the connex edges are of type <Side1> or <Side2>.", py::arg("Face"), py::arg("Co"), py::arg("Map"), py::arg("Type1"), py::arg("Type2"));

// Enums

}