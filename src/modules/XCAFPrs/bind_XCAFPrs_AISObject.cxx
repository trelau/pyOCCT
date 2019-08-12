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
#include <AIS_ColoredShape.hxx>
#include <TDF_Label.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_MaterialAspect.hxx>
#include <Standard_Handle.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <Prs3d_Presentation.hxx>
#include <Prs3d_Drawer.hxx>
#include <Quantity_Color.hxx>
#include <Quantity_ColorRGBA.hxx>
#include <XCAFPrs_Style.hxx>
#include <XCAFPrs_AISObject.hxx>
#include <Standard_Type.hxx>

void bind_XCAFPrs_AISObject(py::module &mod){

py::class_<XCAFPrs_AISObject, opencascade::handle<XCAFPrs_AISObject>, AIS_ColoredShape> cls_XCAFPrs_AISObject(mod, "XCAFPrs_AISObject", "Implements AIS_InteractiveObject functionality for shape in DECAF document.");

// Constructors
cls_XCAFPrs_AISObject.def(py::init<const TDF_Label &>(), py::arg("theLabel"));

// Fields

// Methods
cls_XCAFPrs_AISObject.def("GetLabel", (const TDF_Label & (XCAFPrs_AISObject::*)() const) &XCAFPrs_AISObject::GetLabel, "Returns the label which was visualised by this presentation");
cls_XCAFPrs_AISObject.def("SetLabel", (void (XCAFPrs_AISObject::*)(const TDF_Label &)) &XCAFPrs_AISObject::SetLabel, "Assign the label to this presentation (but does not mark it outdated with SetToUpdate()).", py::arg("theLabel"));
cls_XCAFPrs_AISObject.def("DispatchStyles", [](XCAFPrs_AISObject &self) -> void { return self.DispatchStyles(); });
cls_XCAFPrs_AISObject.def("DispatchStyles", (void (XCAFPrs_AISObject::*)(const Standard_Boolean)) &XCAFPrs_AISObject::DispatchStyles, "Fetch the Shape from associated Label and fill the map of sub-shapes styles. By default, this method is called implicitly within first ::Compute(). Application might call this method explicitly to manipulate styles afterwards.", py::arg("theToSyncStyles"));
cls_XCAFPrs_AISObject.def("SetMaterial", (void (XCAFPrs_AISObject::*)(const Graphic3d_MaterialAspect &)) &XCAFPrs_AISObject::SetMaterial, "Sets the material aspect. This method assigns the new default material without overriding XDE styles. Re-computation of existing presentation is not required after calling this method.", py::arg("theMaterial"));
cls_XCAFPrs_AISObject.def_static("get_type_name_", (const char * (*)()) &XCAFPrs_AISObject::get_type_name, "None");
cls_XCAFPrs_AISObject.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFPrs_AISObject::get_type_descriptor, "None");
cls_XCAFPrs_AISObject.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFPrs_AISObject::*)() const) &XCAFPrs_AISObject::DynamicType, "None");

// Enums

}