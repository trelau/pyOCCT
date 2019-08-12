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
#include <AIS_Shape.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Handle.hxx>
#include <AIS_ColoredDrawer.hxx>
#include <Standard_TypeDef.hxx>
#include <Quantity_Color.hxx>
#include <AIS_DataMapOfShapeDrawer.hxx>
#include <Graphic3d_MaterialAspect.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <Prs3d_Presentation.hxx>
#include <SelectMgr_Selection.hxx>
#include <NCollection_IndexedDataMap.hxx>
#include <TopoDS_Compound.hxx>
#include <TColStd_MapTransientHasher.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <AIS_ColoredShape.hxx>
#include <StdSelect_BRepOwner.hxx>
#include <Standard_Type.hxx>

void bind_AIS_ColoredShape(py::module &mod){

py::class_<AIS_ColoredShape, opencascade::handle<AIS_ColoredShape>, AIS_Shape> cls_AIS_ColoredShape(mod, "AIS_ColoredShape", "Presentation of the shape with customizable sub-shapes properties.");

// Constructors
cls_AIS_ColoredShape.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));
cls_AIS_ColoredShape.def(py::init<const opencascade::handle<AIS_Shape> &>(), py::arg("theShape"));

// Fields

// Methods
cls_AIS_ColoredShape.def("CustomAspects", (opencascade::handle<AIS_ColoredDrawer> (AIS_ColoredShape::*)(const TopoDS_Shape &)) &AIS_ColoredShape::CustomAspects, "Customize properties of specified sub-shape. The shape will be stored in the map but ignored, if it is not sub-shape of main Shape! This method can be used to mark sub-shapes with customizable properties.", py::arg("theShape"));
cls_AIS_ColoredShape.def("ClearCustomAspects", (void (AIS_ColoredShape::*)()) &AIS_ColoredShape::ClearCustomAspects, "Reset the map of custom sub-shape aspects.");
cls_AIS_ColoredShape.def("UnsetCustomAspects", [](AIS_ColoredShape &self, const TopoDS_Shape & a0) -> void { return self.UnsetCustomAspects(a0); });
cls_AIS_ColoredShape.def("UnsetCustomAspects", (void (AIS_ColoredShape::*)(const TopoDS_Shape &, const Standard_Boolean)) &AIS_ColoredShape::UnsetCustomAspects, "Reset custom properties of specified sub-shape.", py::arg("theShape"), py::arg("theToUnregister"));
cls_AIS_ColoredShape.def("SetCustomColor", (void (AIS_ColoredShape::*)(const TopoDS_Shape &, const Quantity_Color &)) &AIS_ColoredShape::SetCustomColor, "Customize color of specified sub-shape", py::arg("theShape"), py::arg("theColor"));
cls_AIS_ColoredShape.def("SetCustomWidth", (void (AIS_ColoredShape::*)(const TopoDS_Shape &, const Standard_Real)) &AIS_ColoredShape::SetCustomWidth, "Customize line width of specified sub-shape", py::arg("theShape"), py::arg("theLineWidth"));
cls_AIS_ColoredShape.def("CustomAspectsMap", (const AIS_DataMapOfShapeDrawer & (AIS_ColoredShape::*)() const) &AIS_ColoredShape::CustomAspectsMap, "Return the map of custom aspects.");
cls_AIS_ColoredShape.def("ChangeCustomAspectsMap", (AIS_DataMapOfShapeDrawer & (AIS_ColoredShape::*)()) &AIS_ColoredShape::ChangeCustomAspectsMap, "Return the map of custom aspects.");
cls_AIS_ColoredShape.def("SetColor", (void (AIS_ColoredShape::*)(const Quantity_Color &)) &AIS_ColoredShape::SetColor, "Setup color of entire shape.", py::arg("theColor"));
cls_AIS_ColoredShape.def("SetWidth", (void (AIS_ColoredShape::*)(const Standard_Real)) &AIS_ColoredShape::SetWidth, "Setup line width of entire shape.", py::arg("theLineWidth"));
cls_AIS_ColoredShape.def("SetTransparency", (void (AIS_ColoredShape::*)(const Standard_Real)) &AIS_ColoredShape::SetTransparency, "Sets transparency value.", py::arg("theValue"));
cls_AIS_ColoredShape.def("UnsetTransparency", (void (AIS_ColoredShape::*)()) &AIS_ColoredShape::UnsetTransparency, "Removes the setting for transparency in the reconstructed compound shape.");
cls_AIS_ColoredShape.def("SetMaterial", (void (AIS_ColoredShape::*)(const Graphic3d_MaterialAspect &)) &AIS_ColoredShape::SetMaterial, "Sets the material aspect.", py::arg("theAspect"));
cls_AIS_ColoredShape.def_static("get_type_name_", (const char * (*)()) &AIS_ColoredShape::get_type_name, "None");
cls_AIS_ColoredShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_ColoredShape::get_type_descriptor, "None");
cls_AIS_ColoredShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_ColoredShape::*)() const) &AIS_ColoredShape::DynamicType, "None");

// Enums

}