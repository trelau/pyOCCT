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
#include <PrsMgr_PresentableObject.hxx>
#include <Standard_Handle.hxx>
#include <StdSelect_Shape.hxx>
#include <Standard_Type.hxx>
#include <TopoDS_Shape.hxx>
#include <Prs3d_Drawer.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <Prs3d_Presentation.hxx>
#include <Standard_TypeDef.hxx>
#include <Prs3d_Projector.hxx>
#include <Geom_Transformation.hxx>

void bind_StdSelect_Shape(py::module &mod){

py::class_<StdSelect_Shape, opencascade::handle<StdSelect_Shape>, PrsMgr_PresentableObject> cls_StdSelect_Shape(mod, "StdSelect_Shape", "Presentable shape only for purpose of display for BRepOwner...");

// Constructors
cls_StdSelect_Shape.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));
cls_StdSelect_Shape.def(py::init<const TopoDS_Shape &, const opencascade::handle<Prs3d_Drawer> &>(), py::arg("theShape"), py::arg("theDrawer"));

// Fields

// Methods
cls_StdSelect_Shape.def_static("get_type_name_", (const char * (*)()) &StdSelect_Shape::get_type_name, "None");
cls_StdSelect_Shape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdSelect_Shape::get_type_descriptor, "None");
cls_StdSelect_Shape.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdSelect_Shape::*)() const) &StdSelect_Shape::DynamicType, "None");
cls_StdSelect_Shape.def("Compute", [](StdSelect_Shape &self, const opencascade::handle<PrsMgr_PresentationManager3d> & a0, const opencascade::handle<Prs3d_Presentation> & a1) -> void { return self.Compute(a0, a1); });
cls_StdSelect_Shape.def("Compute", (void (StdSelect_Shape::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const opencascade::handle<Prs3d_Presentation> &, const Standard_Integer)) &StdSelect_Shape::Compute, "None", py::arg("aPresentationManager"), py::arg("aPresentation"), py::arg("aMode"));
cls_StdSelect_Shape.def("Compute", (void (StdSelect_Shape::*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Geom_Transformation> &, const opencascade::handle<Prs3d_Presentation> &)) &StdSelect_Shape::Compute, "computes the presentation according to a point of view given by <aProjector>. To be Used when the associated degenerated Presentations have been transformed by <aTrsf> which is not a Pure Translation. The HLR Prs can't be deducted automatically WARNING :<aTrsf> must be applied to the object to display before computation !!!", py::arg("aProjector"), py::arg("aTrsf"), py::arg("aPresentation"));
cls_StdSelect_Shape.def("Shape", (const TopoDS_Shape & (StdSelect_Shape::*)() const) &StdSelect_Shape::Shape, "None");
cls_StdSelect_Shape.def("Shape", (void (StdSelect_Shape::*)(const TopoDS_Shape &)) &StdSelect_Shape::Shape, "None", py::arg("theShape"));

// Enums

}