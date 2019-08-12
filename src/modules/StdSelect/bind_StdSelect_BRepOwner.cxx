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
#include <SelectMgr_EntityOwner.hxx>
#include <Standard_Handle.hxx>
#include <StdSelect_BRepOwner.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <SelectMgr_SelectableObject.hxx>
#include <PrsMgr_PresentationManager.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <Prs3d_Drawer.hxx>
#include <TopLoc_Location.hxx>
#include <V3d_Viewer.hxx>
#include <StdSelect_Shape.hxx>

void bind_StdSelect_BRepOwner(py::module &mod){

py::class_<StdSelect_BRepOwner, opencascade::handle<StdSelect_BRepOwner>, SelectMgr_EntityOwner> cls_StdSelect_BRepOwner(mod, "StdSelect_BRepOwner", "Defines Specific Owners for Sensitive Primitives (Sensitive Segments,Circles...). Used in Dynamic Selection Mechanism. A BRepOwner has an Owner (the shape it represents) and Users (One or More Transient entities). The highlight-unhighlight methods are empty and must be redefined by each User.");

// Constructors
cls_StdSelect_BRepOwner.def(py::init<const Standard_Integer>(), py::arg("aPriority"));
cls_StdSelect_BRepOwner.def(py::init<const TopoDS_Shape &>(), py::arg("aShape"));
cls_StdSelect_BRepOwner.def(py::init<const TopoDS_Shape &, const Standard_Integer>(), py::arg("aShape"), py::arg("aPriority"));
cls_StdSelect_BRepOwner.def(py::init<const TopoDS_Shape &, const Standard_Integer, const Standard_Boolean>(), py::arg("aShape"), py::arg("aPriority"), py::arg("ComesFromDecomposition"));
cls_StdSelect_BRepOwner.def(py::init<const TopoDS_Shape &, const opencascade::handle<SelectMgr_SelectableObject> &>(), py::arg("aShape"), py::arg("theOrigin"));
cls_StdSelect_BRepOwner.def(py::init<const TopoDS_Shape &, const opencascade::handle<SelectMgr_SelectableObject> &, const Standard_Integer>(), py::arg("aShape"), py::arg("theOrigin"), py::arg("aPriority"));
cls_StdSelect_BRepOwner.def(py::init<const TopoDS_Shape &, const opencascade::handle<SelectMgr_SelectableObject> &, const Standard_Integer, const Standard_Boolean>(), py::arg("aShape"), py::arg("theOrigin"), py::arg("aPriority"), py::arg("FromDecomposition"));

// Fields

// Methods
cls_StdSelect_BRepOwner.def_static("get_type_name_", (const char * (*)()) &StdSelect_BRepOwner::get_type_name, "None");
cls_StdSelect_BRepOwner.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdSelect_BRepOwner::get_type_descriptor, "None");
cls_StdSelect_BRepOwner.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdSelect_BRepOwner::*)() const) &StdSelect_BRepOwner::DynamicType, "None");
cls_StdSelect_BRepOwner.def("HasShape", (Standard_Boolean (StdSelect_BRepOwner::*)() const) &StdSelect_BRepOwner::HasShape, "returns False if no shape was set");
// cls_StdSelect_BRepOwner.def("Set", [](StdSelect_BRepOwner &self, const TopoDS_Shape & a0) -> void { return self.Set(a0); });
// cls_StdSelect_BRepOwner.def("Set", (void (StdSelect_BRepOwner::*)(const TopoDS_Shape &, const Standard_Boolean)) &StdSelect_BRepOwner::Set, "<FromDecomposition> indicates whether <aShape> comes from decomposition of a bigger shape.", py::arg("aShape"), py::arg("FromDecomposition"));
cls_StdSelect_BRepOwner.def("Shape", (const TopoDS_Shape & (StdSelect_BRepOwner::*)() const) &StdSelect_BRepOwner::Shape, "None");
cls_StdSelect_BRepOwner.def("HasHilightMode", (Standard_Boolean (StdSelect_BRepOwner::*)() const) &StdSelect_BRepOwner::HasHilightMode, "Returns true if this framework has a highlight mode defined for it.");
cls_StdSelect_BRepOwner.def("SetHilightMode", (void (StdSelect_BRepOwner::*)(const Standard_Integer)) &StdSelect_BRepOwner::SetHilightMode, "Sets the highlight mode for this framework. This defines the type of display used to highlight the owner of the shape when it is detected by the selector. The default type of display is wireframe, defined by the index 0.", py::arg("theMode"));
cls_StdSelect_BRepOwner.def("ResetHilightMode", (void (StdSelect_BRepOwner::*)()) &StdSelect_BRepOwner::ResetHilightMode, "Resets the higlight mode for this framework. This defines the type of display used to highlight the owner of the shape when it is detected by the selector. The default type of display is wireframe, defined by the index 0.");
cls_StdSelect_BRepOwner.def("HilightMode", (Standard_Integer (StdSelect_BRepOwner::*)() const) &StdSelect_BRepOwner::HilightMode, "Returns the highlight mode for this framework. This defines the type of display used to highlight the owner of the shape when it is detected by the selector. The default type of display is wireframe, defined by the index 0.");
cls_StdSelect_BRepOwner.def("IsHilighted", [](StdSelect_BRepOwner &self, const opencascade::handle<PrsMgr_PresentationManager> & a0) -> Standard_Boolean { return self.IsHilighted(a0); });
cls_StdSelect_BRepOwner.def("IsHilighted", (Standard_Boolean (StdSelect_BRepOwner::*)(const opencascade::handle<PrsMgr_PresentationManager> &, const Standard_Integer) const) &StdSelect_BRepOwner::IsHilighted, "Returns true if an object with the selection mode aMode is highlighted in the presentation manager aPM.", py::arg("aPM"), py::arg("aMode"));
cls_StdSelect_BRepOwner.def("HilightWithColor", [](StdSelect_BRepOwner &self, const opencascade::handle<PrsMgr_PresentationManager3d> & a0, const opencascade::handle<Prs3d_Drawer> & a1) -> void { return self.HilightWithColor(a0, a1); });
cls_StdSelect_BRepOwner.def("HilightWithColor", (void (StdSelect_BRepOwner::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Integer)) &StdSelect_BRepOwner::HilightWithColor, "None", py::arg("thePM"), py::arg("theStyle"), py::arg("theMode"));
cls_StdSelect_BRepOwner.def("Unhilight", [](StdSelect_BRepOwner &self, const opencascade::handle<PrsMgr_PresentationManager> & a0) -> void { return self.Unhilight(a0); });
cls_StdSelect_BRepOwner.def("Unhilight", (void (StdSelect_BRepOwner::*)(const opencascade::handle<PrsMgr_PresentationManager> &, const Standard_Integer)) &StdSelect_BRepOwner::Unhilight, "Removes highlighting from the type of shape identified the selection mode aMode in the presentation manager aPM.", py::arg("aPM"), py::arg("aMode"));
cls_StdSelect_BRepOwner.def("Clear", [](StdSelect_BRepOwner &self, const opencascade::handle<PrsMgr_PresentationManager> & a0) -> void { return self.Clear(a0); });
cls_StdSelect_BRepOwner.def("Clear", (void (StdSelect_BRepOwner::*)(const opencascade::handle<PrsMgr_PresentationManager> &, const Standard_Integer)) &StdSelect_BRepOwner::Clear, "Clears the presentation manager object aPM of all shapes with the selection mode aMode.", py::arg("aPM"), py::arg("aMode"));
cls_StdSelect_BRepOwner.def("SetLocation", (void (StdSelect_BRepOwner::*)(const TopLoc_Location &)) &StdSelect_BRepOwner::SetLocation, "None", py::arg("aLoc"));
cls_StdSelect_BRepOwner.def("ResetLocation", (void (StdSelect_BRepOwner::*)()) &StdSelect_BRepOwner::ResetLocation, "None");
cls_StdSelect_BRepOwner.def("UpdateHighlightTrsf", (void (StdSelect_BRepOwner::*)(const opencascade::handle<V3d_Viewer> &, const opencascade::handle<PrsMgr_PresentationManager3d> &, const Standard_Integer)) &StdSelect_BRepOwner::UpdateHighlightTrsf, "Implements immediate application of location transformation of parent object to dynamic highlight structure", py::arg("theViewer"), py::arg("theManager"), py::arg("theDispMode"));

// Enums

}