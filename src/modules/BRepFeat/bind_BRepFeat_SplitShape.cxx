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
#include <BRepBuilderAPI_MakeShape.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_SequenceOfShape.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Compound.hxx>
#include <TopTools_ListOfShape.hxx>
#include <LocOpe_Spliter.hxx>
#include <Standard_Handle.hxx>
#include <LocOpe_WiresOnShape.hxx>
#include <BRepFeat_SplitShape.hxx>

void bind_BRepFeat_SplitShape(py::module &mod){

py::class_<BRepFeat_SplitShape, BRepBuilderAPI_MakeShape> cls_BRepFeat_SplitShape(mod, "BRepFeat_SplitShape", "One of the most significant aspects of BRepFeat functionality is the use of local operations as opposed to global ones. In a global operation, you would first construct a form of the type you wanted in your final feature, and then remove matter so that it could fit into your initial basis object. In a local operation, however, you specify the domain of the feature construction with aspects of the shape on which the feature is being created. These semantics are expressed in terms of a member shape of the basis shape from which - or up to which - matter will be added or removed. As a result, local operations make calculations simpler and faster than global operations. In BRepFeat, the semantics of local operations define features constructed from a contour or a part of the basis shape referred to as the tool. In a SplitShape object, wires or edges of a face in the basis shape to be used as a part of the feature are cut out and projected to a plane outside or inside the basis shape. By rebuilding the initial shape incorporating the edges and the faces of the tool, protrusion or depression features can be constructed.");

// Constructors
cls_BRepFeat_SplitShape.def(py::init<>());
cls_BRepFeat_SplitShape.def(py::init<const TopoDS_Shape &>(), py::arg("S"));

// Fields

// Methods
// cls_BRepFeat_SplitShape.def_static("operator new_", (void * (*)(size_t)) &BRepFeat_SplitShape::operator new, "None", py::arg("theSize"));
// cls_BRepFeat_SplitShape.def_static("operator delete_", (void (*)(void *)) &BRepFeat_SplitShape::operator delete, "None", py::arg("theAddress"));
// cls_BRepFeat_SplitShape.def_static("operator new[]_", (void * (*)(size_t)) &BRepFeat_SplitShape::operator new[], "None", py::arg("theSize"));
// cls_BRepFeat_SplitShape.def_static("operator delete[]_", (void (*)(void *)) &BRepFeat_SplitShape::operator delete[], "None", py::arg("theAddress"));
// cls_BRepFeat_SplitShape.def_static("operator new_", (void * (*)(size_t, void *)) &BRepFeat_SplitShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepFeat_SplitShape.def_static("operator delete_", (void (*)(void *, void *)) &BRepFeat_SplitShape::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepFeat_SplitShape.def("Add", (Standard_Boolean (BRepFeat_SplitShape::*)(const TopTools_SequenceOfShape &)) &BRepFeat_SplitShape::Add, "Add splitting edges or wires for whole initial shape withot additional specification edge->face, edge->edge This method puts edge on the corresponding faces from initial shape", py::arg("theEdges"));
cls_BRepFeat_SplitShape.def("Init", (void (BRepFeat_SplitShape::*)(const TopoDS_Shape &)) &BRepFeat_SplitShape::Init, "Initializes the process on the shape <S>.", py::arg("S"));
cls_BRepFeat_SplitShape.def("SetCheckInterior", (void (BRepFeat_SplitShape::*)(const Standard_Boolean)) &BRepFeat_SplitShape::SetCheckInterior, "Set the flag of check internal intersections default value is True (to check)", py::arg("ToCheckInterior"));
cls_BRepFeat_SplitShape.def("Add", (void (BRepFeat_SplitShape::*)(const TopoDS_Wire &, const TopoDS_Face &)) &BRepFeat_SplitShape::Add, "Adds the wire <W> on the face <F>. Raises NoSuchObject if <F> does not belong to the original shape.", py::arg("W"), py::arg("F"));
cls_BRepFeat_SplitShape.def("Add", (void (BRepFeat_SplitShape::*)(const TopoDS_Edge &, const TopoDS_Face &)) &BRepFeat_SplitShape::Add, "Adds the edge <E> on the face <F>.", py::arg("E"), py::arg("F"));
cls_BRepFeat_SplitShape.def("Add", (void (BRepFeat_SplitShape::*)(const TopoDS_Compound &, const TopoDS_Face &)) &BRepFeat_SplitShape::Add, "Adds the compound <Comp> on the face <F>. The compound <Comp> must consist of edges lying on the face <F>. If edges are geometrically connected, they must be connected topologically, i.e. they must share common vertices.", py::arg("Comp"), py::arg("F"));
cls_BRepFeat_SplitShape.def("Add", (void (BRepFeat_SplitShape::*)(const TopoDS_Edge &, const TopoDS_Edge &)) &BRepFeat_SplitShape::Add, "Adds the edge <E> on the existing edge <EOn>.", py::arg("E"), py::arg("EOn"));
cls_BRepFeat_SplitShape.def("DirectLeft", (const TopTools_ListOfShape & (BRepFeat_SplitShape::*)() const) &BRepFeat_SplitShape::DirectLeft, "Returns the faces which are the left of the projected wires.");
cls_BRepFeat_SplitShape.def("Left", (const TopTools_ListOfShape & (BRepFeat_SplitShape::*)() const) &BRepFeat_SplitShape::Left, "Returns the faces of the 'left' part on the shape. (It is build from DirectLeft, with the faces connected to this set, and so on...). Raises NotDone if IsDone returns <Standard_False>.");
cls_BRepFeat_SplitShape.def("Build", (void (BRepFeat_SplitShape::*)()) &BRepFeat_SplitShape::Build, "Builds the cut and the resulting faces and edges as well.");
cls_BRepFeat_SplitShape.def("IsDeleted", (Standard_Boolean (BRepFeat_SplitShape::*)(const TopoDS_Shape &)) &BRepFeat_SplitShape::IsDeleted, "Returns true if the shape has been deleted.", py::arg("S"));
cls_BRepFeat_SplitShape.def("Modified", (const TopTools_ListOfShape & (BRepFeat_SplitShape::*)(const TopoDS_Shape &)) &BRepFeat_SplitShape::Modified, "Returns the list of generated Faces.", py::arg("F"));

// Enums

}