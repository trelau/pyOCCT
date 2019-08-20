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
#include <Standard_TypeDef.hxx>
#include <TopoDS_Edge.hxx>
#include <TColGeom_SequenceOfCurve.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <BRepFeat_StatusError.hxx>
#include <BRepFeat_MakeDPrism.hxx>

void bind_BRepFeat_MakeDPrism(py::module &mod){

py::class_<BRepFeat_MakeDPrism, std::unique_ptr<BRepFeat_MakeDPrism>, BRepFeat_Form> cls_BRepFeat_MakeDPrism(mod, "BRepFeat_MakeDPrism", "Describes functions to build draft prism topologies from basis shape surfaces. These can be depressions or protrusions. The semantics of draft prism feature creation is based on the construction of shapes: - along a length - up to a limiting face - from a limiting face to a height. The shape defining construction of the draft prism feature can be either the supporting edge or the concerned area of a face. In case of the supporting edge, this contour can be attached to a face of the basis shape by binding. When the contour is bound to this face, the information that the contour will slide on the face becomes available to the relevant class methods. In case of the concerned area of a face, you could, for example, cut it out and move it to a different height which will define the limiting face of a protrusion or depression.");

// Constructors
cls_BRepFeat_MakeDPrism.def(py::init<const TopoDS_Shape &, const TopoDS_Face &, const TopoDS_Face &, const Standard_Real, const Standard_Integer, const Standard_Boolean>(), py::arg("Sbase"), py::arg("Pbase"), py::arg("Skface"), py::arg("Angle"), py::arg("Fuse"), py::arg("Modify"));
cls_BRepFeat_MakeDPrism.def(py::init<>());

// Fields

// Methods
// cls_BRepFeat_MakeDPrism.def_static("operator new_", (void * (*)(size_t)) &BRepFeat_MakeDPrism::operator new, "None", py::arg("theSize"));
// cls_BRepFeat_MakeDPrism.def_static("operator delete_", (void (*)(void *)) &BRepFeat_MakeDPrism::operator delete, "None", py::arg("theAddress"));
// cls_BRepFeat_MakeDPrism.def_static("operator new[]_", (void * (*)(size_t)) &BRepFeat_MakeDPrism::operator new[], "None", py::arg("theSize"));
// cls_BRepFeat_MakeDPrism.def_static("operator delete[]_", (void (*)(void *)) &BRepFeat_MakeDPrism::operator delete[], "None", py::arg("theAddress"));
// cls_BRepFeat_MakeDPrism.def_static("operator new_", (void * (*)(size_t, void *)) &BRepFeat_MakeDPrism::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepFeat_MakeDPrism.def_static("operator delete_", (void (*)(void *, void *)) &BRepFeat_MakeDPrism::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepFeat_MakeDPrism.def("Init", (void (BRepFeat_MakeDPrism::*)(const TopoDS_Shape &, const TopoDS_Face &, const TopoDS_Face &, const Standard_Real, const Standard_Integer, const Standard_Boolean)) &BRepFeat_MakeDPrism::Init, "Initializes this algorithm for building draft prisms along surfaces. A face Pbase is selected in the basis shape Sbase to serve as the basis from the draft prism. The draft will be defined by the angle Angle and Fuse offers a choice between: - removing matter with a Boolean cut using the setting 0 - adding matter with Boolean fusion using the setting 1. The sketch face Skface serves to determine the type of operation. If it is inside the basis shape, a local operation such as glueing can be performed.", py::arg("Sbase"), py::arg("Pbase"), py::arg("Skface"), py::arg("Angle"), py::arg("Fuse"), py::arg("Modify"));
cls_BRepFeat_MakeDPrism.def("Add", (void (BRepFeat_MakeDPrism::*)(const TopoDS_Edge &, const TopoDS_Face &)) &BRepFeat_MakeDPrism::Add, "Indicates that the edge <E> will slide on the face <OnFace>. Raises ConstructionError if the face does not belong to the basis shape, or the edge to the prismed shape.", py::arg("E"), py::arg("OnFace"));
cls_BRepFeat_MakeDPrism.def("Perform", (void (BRepFeat_MakeDPrism::*)(const Standard_Real)) &BRepFeat_MakeDPrism::Perform, "None", py::arg("Height"));
cls_BRepFeat_MakeDPrism.def("Perform", (void (BRepFeat_MakeDPrism::*)(const TopoDS_Shape &)) &BRepFeat_MakeDPrism::Perform, "None", py::arg("Until"));
cls_BRepFeat_MakeDPrism.def("Perform", (void (BRepFeat_MakeDPrism::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepFeat_MakeDPrism::Perform, "Assigns one of the following semantics - to a height Height - to a face Until - from a face From to a height Until. Reconstructs the feature topologically according to the semantic option chosen.", py::arg("From"), py::arg("Until"));
cls_BRepFeat_MakeDPrism.def("PerformUntilEnd", (void (BRepFeat_MakeDPrism::*)()) &BRepFeat_MakeDPrism::PerformUntilEnd, "Realizes a semi-infinite prism, limited by the position of the prism base.");
cls_BRepFeat_MakeDPrism.def("PerformFromEnd", (void (BRepFeat_MakeDPrism::*)(const TopoDS_Shape &)) &BRepFeat_MakeDPrism::PerformFromEnd, "Realizes a semi-infinite prism, limited by the face Funtil.", py::arg("FUntil"));
cls_BRepFeat_MakeDPrism.def("PerformThruAll", (void (BRepFeat_MakeDPrism::*)()) &BRepFeat_MakeDPrism::PerformThruAll, "Builds an infinite prism. The infinite descendants will not be kept in the result.");
cls_BRepFeat_MakeDPrism.def("PerformUntilHeight", (void (BRepFeat_MakeDPrism::*)(const TopoDS_Shape &, const Standard_Real)) &BRepFeat_MakeDPrism::PerformUntilHeight, "Assigns both a limiting shape, Until from TopoDS_Shape, and a height, Height at which to stop generation of the prism feature.", py::arg("Until"), py::arg("Height"));
cls_BRepFeat_MakeDPrism.def("Curves", (void (BRepFeat_MakeDPrism::*)(TColGeom_SequenceOfCurve &)) &BRepFeat_MakeDPrism::Curves, "None", py::arg("S"));
cls_BRepFeat_MakeDPrism.def("BarycCurve", (opencascade::handle<Geom_Curve> (BRepFeat_MakeDPrism::*)()) &BRepFeat_MakeDPrism::BarycCurve, "None");
cls_BRepFeat_MakeDPrism.def("BossEdges", (void (BRepFeat_MakeDPrism::*)(const Standard_Integer)) &BRepFeat_MakeDPrism::BossEdges, "Determination of TopEdges and LatEdges. sig = 1 -> TopEdges = FirstShape of the DPrism sig = 2 -> TOpEdges = LastShape of the DPrism", py::arg("sig"));
cls_BRepFeat_MakeDPrism.def("TopEdges", (const TopTools_ListOfShape & (BRepFeat_MakeDPrism::*)()) &BRepFeat_MakeDPrism::TopEdges, "Returns the list of TopoDS Edges of the top of the boss.");
cls_BRepFeat_MakeDPrism.def("LatEdges", (const TopTools_ListOfShape & (BRepFeat_MakeDPrism::*)()) &BRepFeat_MakeDPrism::LatEdges, "Returns the list of TopoDS Edges of the bottom of the boss.");

// Enums

}