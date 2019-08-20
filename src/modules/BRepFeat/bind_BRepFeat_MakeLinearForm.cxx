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
#include <BRepFeat_RibSlot.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Wire.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Plane.hxx>
#include <gp_Vec.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <TopTools_ListOfShape.hxx>
#include <gp_Pnt.hxx>
#include <Geom_Curve.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <BRepFeat_MakeLinearForm.hxx>

void bind_BRepFeat_MakeLinearForm(py::module &mod){

py::class_<BRepFeat_MakeLinearForm, std::unique_ptr<BRepFeat_MakeLinearForm>, BRepFeat_RibSlot> cls_BRepFeat_MakeLinearForm(mod, "BRepFeat_MakeLinearForm", "Builds a rib or a groove along a developable, planar surface. The semantics of mechanical features is built around giving thickness to a contour. This thickness can either be symmetrical - on one side of the contour - or dissymmetrical - on both sides. As in the semantics of form features, the thickness is defined by construction of shapes in specific contexts. The development contexts differ, however, in case of mechanical features. Here they include extrusion: - to a limiting face of the basis shape - to or from a limiting plane - to a height.");

// Constructors
cls_BRepFeat_MakeLinearForm.def(py::init<>());
cls_BRepFeat_MakeLinearForm.def(py::init<const TopoDS_Shape &, const TopoDS_Wire &, const opencascade::handle<Geom_Plane> &, const gp_Vec &, const gp_Vec &, const Standard_Integer, const Standard_Boolean>(), py::arg("Sbase"), py::arg("W"), py::arg("P"), py::arg("Direction"), py::arg("Direction1"), py::arg("Fuse"), py::arg("Modify"));

// Fields

// Methods
// cls_BRepFeat_MakeLinearForm.def_static("operator new_", (void * (*)(size_t)) &BRepFeat_MakeLinearForm::operator new, "None", py::arg("theSize"));
// cls_BRepFeat_MakeLinearForm.def_static("operator delete_", (void (*)(void *)) &BRepFeat_MakeLinearForm::operator delete, "None", py::arg("theAddress"));
// cls_BRepFeat_MakeLinearForm.def_static("operator new[]_", (void * (*)(size_t)) &BRepFeat_MakeLinearForm::operator new[], "None", py::arg("theSize"));
// cls_BRepFeat_MakeLinearForm.def_static("operator delete[]_", (void (*)(void *)) &BRepFeat_MakeLinearForm::operator delete[], "None", py::arg("theAddress"));
// cls_BRepFeat_MakeLinearForm.def_static("operator new_", (void * (*)(size_t, void *)) &BRepFeat_MakeLinearForm::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepFeat_MakeLinearForm.def_static("operator delete_", (void (*)(void *, void *)) &BRepFeat_MakeLinearForm::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepFeat_MakeLinearForm.def("Init", (void (BRepFeat_MakeLinearForm::*)(const TopoDS_Shape &, const TopoDS_Wire &, const opencascade::handle<Geom_Plane> &, const gp_Vec &, const gp_Vec &, const Standard_Integer, const Standard_Boolean)) &BRepFeat_MakeLinearForm::Init, "Initializes this construction algorithm. A contour W, a shape Sbase and a plane P are initialized to serve as the basic elements in the construction of the rib or groove. The vectors for defining the direction(s) in which thickness will be built up are given by Direction and Direction1. Fuse offers a choice between: - removing matter with a Boolean cut using the setting 0 in case of the groove - adding matter with Boolean fusion using the setting 1 in case of the rib.", py::arg("Sbase"), py::arg("W"), py::arg("P"), py::arg("Direction"), py::arg("Direction1"), py::arg("Fuse"), py::arg("Modify"));
cls_BRepFeat_MakeLinearForm.def("Add", (void (BRepFeat_MakeLinearForm::*)(const TopoDS_Edge &, const TopoDS_Face &)) &BRepFeat_MakeLinearForm::Add, "Indicates that the edge <E> will slide on the face <OnFace>. Raises ConstructionError if the face does not belong to the basis shape, or the edge to the prismed shape.", py::arg("E"), py::arg("OnFace"));
cls_BRepFeat_MakeLinearForm.def("Perform", (void (BRepFeat_MakeLinearForm::*)()) &BRepFeat_MakeLinearForm::Perform, "Performs a prism from the wire to the plane along the basis shape Sbase. Reconstructs the feature topologically.");
// cls_BRepFeat_MakeLinearForm.def("TransformShapeFU", (void (BRepFeat_MakeLinearForm::*)(const Standard_Integer)) &BRepFeat_MakeLinearForm::TransformShapeFU, "Limits construction of the linear form feature by using one of the following three semantics: - from a limiting plane - to a limiting plane - from one limiting plane to another. The setting is provided by a flag, flag, which can be set to from and/or until. The third semantic possibility above is selected by showing both from and until at the same time.", py::arg("flag"));
cls_BRepFeat_MakeLinearForm.def("Propagate", [](BRepFeat_MakeLinearForm &self, TopTools_ListOfShape & L, const TopoDS_Face & F, const gp_Pnt & FPoint, const gp_Pnt & LPoint, Standard_Boolean & falseside){ Standard_Boolean rv = self.Propagate(L, F, FPoint, LPoint, falseside); return std::tuple<Standard_Boolean, Standard_Boolean &>(rv, falseside); }, "None", py::arg("L"), py::arg("F"), py::arg("FPoint"), py::arg("LPoint"), py::arg("falseside"));

// Enums

}