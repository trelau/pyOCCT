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
#include <IGESData_ViewKindEntity.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_XYZ.hxx>
#include <gp_XY.hxx>
#include <Standard_Handle.hxx>
#include <gp_Vec.hxx>
#include <gp_Pnt.hxx>
#include <gp_Pnt2d.hxx>
#include <IGESData_TransfEntity.hxx>
#include <IGESDraw_PerspectiveView.hxx>
#include <Standard_Type.hxx>

void bind_IGESDraw_PerspectiveView(py::module &mod){

py::class_<IGESDraw_PerspectiveView, opencascade::handle<IGESDraw_PerspectiveView>, IGESData_ViewKindEntity> cls_IGESDraw_PerspectiveView(mod, "IGESDraw_PerspectiveView", "defines IGESPerspectiveView, Type <410> Form <1> in package IGESDraw");

// Constructors
cls_IGESDraw_PerspectiveView.def(py::init<>());

// Fields

// Methods
cls_IGESDraw_PerspectiveView.def("Init", (void (IGESDraw_PerspectiveView::*)(const Standard_Integer, const Standard_Real, const gp_XYZ &, const gp_XYZ &, const gp_XYZ &, const gp_XYZ &, const Standard_Real, const gp_XY &, const gp_XY &, const Standard_Integer, const Standard_Real, const Standard_Real)) &IGESDraw_PerspectiveView::Init, "This method is used to set the fields of the class PerspectiveView - aViewNumber : The desired view - aScaleFactor : Scale factor - aViewNormalVector : View plane normal vector (model space) - aViewReferencePoint : View reference point (model space) - aCenterOfProjection : Center Of Projection (model space) - aViewUpVector : View up vector (model space) - aViewPlaneDistance : View plane distance (model space) - aTopLeft : Top-left point of clipping window - aBottomRight : Bottom-right point of clipping window - aDepthClip : Depth clipping indicator - aBackPlaneDistance : Distance of back clipping plane - aFrontPlaneDistance : Distance of front clipping plane", py::arg("aViewNumber"), py::arg("aScaleFactor"), py::arg("aViewNormalVector"), py::arg("aViewReferencePoint"), py::arg("aCenterOfProjection"), py::arg("aViewUpVector"), py::arg("aViewPlaneDistance"), py::arg("aTopLeft"), py::arg("aBottomRight"), py::arg("aDepthClip"), py::arg("aBackPlaneDistance"), py::arg("aFrontPlaneDistance"));
cls_IGESDraw_PerspectiveView.def("IsSingle", (Standard_Boolean (IGESDraw_PerspectiveView::*)() const) &IGESDraw_PerspectiveView::IsSingle, "Returns True (for a single view)");
cls_IGESDraw_PerspectiveView.def("NbViews", (Standard_Integer (IGESDraw_PerspectiveView::*)() const) &IGESDraw_PerspectiveView::NbViews, "Returns 1 (single view)");
cls_IGESDraw_PerspectiveView.def("ViewItem", (opencascade::handle<IGESData_ViewKindEntity> (IGESDraw_PerspectiveView::*)(const Standard_Integer) const) &IGESDraw_PerspectiveView::ViewItem, "For a single view, returns <me> whatever <num>", py::arg("num"));
cls_IGESDraw_PerspectiveView.def("ViewNumber", (Standard_Integer (IGESDraw_PerspectiveView::*)() const) &IGESDraw_PerspectiveView::ViewNumber, "returns the view number associated with <me>");
cls_IGESDraw_PerspectiveView.def("ScaleFactor", (Standard_Real (IGESDraw_PerspectiveView::*)() const) &IGESDraw_PerspectiveView::ScaleFactor, "returns the scale factor associated with <me>");
cls_IGESDraw_PerspectiveView.def("ViewNormalVector", (gp_Vec (IGESDraw_PerspectiveView::*)() const) &IGESDraw_PerspectiveView::ViewNormalVector, "returns the View plane normal vector (model space)");
cls_IGESDraw_PerspectiveView.def("ViewReferencePoint", (gp_Pnt (IGESDraw_PerspectiveView::*)() const) &IGESDraw_PerspectiveView::ViewReferencePoint, "returns the View reference point (model space)");
cls_IGESDraw_PerspectiveView.def("CenterOfProjection", (gp_Pnt (IGESDraw_PerspectiveView::*)() const) &IGESDraw_PerspectiveView::CenterOfProjection, "returns the Center Of Projection (model space)");
cls_IGESDraw_PerspectiveView.def("ViewUpVector", (gp_Vec (IGESDraw_PerspectiveView::*)() const) &IGESDraw_PerspectiveView::ViewUpVector, "returns the View up vector (model space)");
cls_IGESDraw_PerspectiveView.def("ViewPlaneDistance", (Standard_Real (IGESDraw_PerspectiveView::*)() const) &IGESDraw_PerspectiveView::ViewPlaneDistance, "returns the View plane distance (model space)");
cls_IGESDraw_PerspectiveView.def("TopLeft", (gp_Pnt2d (IGESDraw_PerspectiveView::*)() const) &IGESDraw_PerspectiveView::TopLeft, "returns the top left point of the clipping window");
cls_IGESDraw_PerspectiveView.def("BottomRight", (gp_Pnt2d (IGESDraw_PerspectiveView::*)() const) &IGESDraw_PerspectiveView::BottomRight, "returns the bottom right point of the clipping window");
cls_IGESDraw_PerspectiveView.def("DepthClip", (Standard_Integer (IGESDraw_PerspectiveView::*)() const) &IGESDraw_PerspectiveView::DepthClip, "returns the Depth clipping indicator 0 = No depth clipping 1 = Back clipping plane ON 2 = Front clipping plane ON 3 = Back and front clipping planes ON");
cls_IGESDraw_PerspectiveView.def("BackPlaneDistance", (Standard_Real (IGESDraw_PerspectiveView::*)() const) &IGESDraw_PerspectiveView::BackPlaneDistance, "returns the View coordinate denoting the location of the back clipping plane");
cls_IGESDraw_PerspectiveView.def("FrontPlaneDistance", (Standard_Real (IGESDraw_PerspectiveView::*)() const) &IGESDraw_PerspectiveView::FrontPlaneDistance, "returns the View coordinate denoting the location of the front clipping plane");
cls_IGESDraw_PerspectiveView.def("ViewMatrix", (opencascade::handle<IGESData_TransfEntity> (IGESDraw_PerspectiveView::*)() const) &IGESDraw_PerspectiveView::ViewMatrix, "returns the Transformation Matrix");
cls_IGESDraw_PerspectiveView.def("ModelToView", (gp_XYZ (IGESDraw_PerspectiveView::*)(const gp_XYZ &) const) &IGESDraw_PerspectiveView::ModelToView, "returns XYX from the Model space to the View space by applying the View Matrix", py::arg("coords"));
cls_IGESDraw_PerspectiveView.def_static("get_type_name_", (const char * (*)()) &IGESDraw_PerspectiveView::get_type_name, "None");
cls_IGESDraw_PerspectiveView.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDraw_PerspectiveView::get_type_descriptor, "None");
cls_IGESDraw_PerspectiveView.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDraw_PerspectiveView::*)() const) &IGESDraw_PerspectiveView::DynamicType, "None");

// Enums

}