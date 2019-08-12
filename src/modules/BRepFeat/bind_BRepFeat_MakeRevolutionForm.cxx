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
#include <gp_Ax1.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <TopTools_ListOfShape.hxx>
#include <gp_Pnt.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <BRepFeat_MakeRevolutionForm.hxx>

void bind_BRepFeat_MakeRevolutionForm(py::module &mod){

py::class_<BRepFeat_MakeRevolutionForm, std::unique_ptr<BRepFeat_MakeRevolutionForm, Deleter<BRepFeat_MakeRevolutionForm>>, BRepFeat_RibSlot> cls_BRepFeat_MakeRevolutionForm(mod, "BRepFeat_MakeRevolutionForm", "MakeRevolutionForm Generates a surface of revolution in the feature as it slides along a revolved face in the basis shape. The semantics of mechanical features is built around giving thickness to a contour. This thickness can either be unilateral - on one side of the contour - or bilateral - on both sides. As in the semantics of form features, the thickness is defined by construction of shapes in specific contexts. The development contexts differ, however,in case of mechanical features. Here they include extrusion: - to a limiting face of the basis shape - to or from a limiting plane - to a height.");

// Constructors
cls_BRepFeat_MakeRevolutionForm.def(py::init<>());
cls_BRepFeat_MakeRevolutionForm.def(py::init<const TopoDS_Shape &, const TopoDS_Wire &, const opencascade::handle<Geom_Plane> &, const gp_Ax1 &, const Standard_Real, const Standard_Real, const Standard_Integer, Standard_Boolean &>(), py::arg("Sbase"), py::arg("W"), py::arg("Plane"), py::arg("Axis"), py::arg("Height1"), py::arg("Height2"), py::arg("Fuse"), py::arg("Sliding"));

// Fields

// Methods
// cls_BRepFeat_MakeRevolutionForm.def_static("operator new_", (void * (*)(size_t)) &BRepFeat_MakeRevolutionForm::operator new, "None", py::arg("theSize"));
// cls_BRepFeat_MakeRevolutionForm.def_static("operator delete_", (void (*)(void *)) &BRepFeat_MakeRevolutionForm::operator delete, "None", py::arg("theAddress"));
// cls_BRepFeat_MakeRevolutionForm.def_static("operator new[]_", (void * (*)(size_t)) &BRepFeat_MakeRevolutionForm::operator new[], "None", py::arg("theSize"));
// cls_BRepFeat_MakeRevolutionForm.def_static("operator delete[]_", (void (*)(void *)) &BRepFeat_MakeRevolutionForm::operator delete[], "None", py::arg("theAddress"));
// cls_BRepFeat_MakeRevolutionForm.def_static("operator new_", (void * (*)(size_t, void *)) &BRepFeat_MakeRevolutionForm::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepFeat_MakeRevolutionForm.def_static("operator delete_", (void (*)(void *, void *)) &BRepFeat_MakeRevolutionForm::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepFeat_MakeRevolutionForm.def("Init", [](BRepFeat_MakeRevolutionForm &self, const TopoDS_Shape & Sbase, const TopoDS_Wire & W, const opencascade::handle<Geom_Plane> & Plane, const gp_Ax1 & Axis, const Standard_Real Height1, const Standard_Real Height2, const Standard_Integer Fuse, Standard_Boolean & Sliding){ self.Init(Sbase, W, Plane, Axis, Height1, Height2, Fuse, Sliding); return Sliding; }, "Initializes this construction algorithm A contour W, a shape Sbase and a plane P are initialized to serve as the basic elements in the construction of the rib or groove. The axis Axis of the revolved surface in the basis shape defines the feature's axis of revolution. Height1 and Height2 may be used as limits to the construction of the feature. Fuse offers a choice between: - removing matter with a Boolean cut using the setting 0 in case of the groove - adding matter with Boolean fusion using the setting 1 in case of the rib.", py::arg("Sbase"), py::arg("W"), py::arg("Plane"), py::arg("Axis"), py::arg("Height1"), py::arg("Height2"), py::arg("Fuse"), py::arg("Sliding"));
cls_BRepFeat_MakeRevolutionForm.def("Add", (void (BRepFeat_MakeRevolutionForm::*)(const TopoDS_Edge &, const TopoDS_Face &)) &BRepFeat_MakeRevolutionForm::Add, "Indicates that the edge <E> will slide on the face <OnFace>. Raises ConstructionError if the face does not belong to the basis shape, or the edge to the prismed shape.", py::arg("E"), py::arg("OnFace"));
cls_BRepFeat_MakeRevolutionForm.def("Perform", (void (BRepFeat_MakeRevolutionForm::*)()) &BRepFeat_MakeRevolutionForm::Perform, "Performs a prism from the wire to the plane along the basis shape S. Reconstructs the feature topologically.");
cls_BRepFeat_MakeRevolutionForm.def("Propagate", [](BRepFeat_MakeRevolutionForm &self, TopTools_ListOfShape & L, const TopoDS_Face & F, const gp_Pnt & FPoint, const gp_Pnt & LPoint, Standard_Boolean & falseside){ Standard_Boolean rv = self.Propagate(L, F, FPoint, LPoint, falseside); return std::tuple<Standard_Boolean, Standard_Boolean &>(rv, falseside); }, "None", py::arg("L"), py::arg("F"), py::arg("FPoint"), py::arg("LPoint"), py::arg("falseside"));

// Enums

}