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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <Graphic3d_LightSet.hxx>
#include <Standard_Type.hxx>
#include <NCollection_IndexedDataMap.hxx>
#include <Graphic3d_CLight.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_TypeOfLightSource.hxx>
#include <Graphic3d_Vec4.hxx>
#include <TCollection_AsciiString.hxx>

void bind_Graphic3d_LightSet(py::module &mod){

py::class_<Graphic3d_LightSet, opencascade::handle<Graphic3d_LightSet>, Standard_Transient> cls_Graphic3d_LightSet(mod, "Graphic3d_LightSet", "Class defining the set of light sources.");

// Constructors
cls_Graphic3d_LightSet.def(py::init<>());

// Fields

// Methods
cls_Graphic3d_LightSet.def_static("get_type_name_", (const char * (*)()) &Graphic3d_LightSet::get_type_name, "None");
cls_Graphic3d_LightSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_LightSet::get_type_descriptor, "None");
cls_Graphic3d_LightSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_LightSet::*)() const) &Graphic3d_LightSet::DynamicType, "None");
cls_Graphic3d_LightSet.def("Lower", (Standard_Integer (Graphic3d_LightSet::*)() const) &Graphic3d_LightSet::Lower, "Return lower light index.");
cls_Graphic3d_LightSet.def("Upper", (Standard_Integer (Graphic3d_LightSet::*)() const) &Graphic3d_LightSet::Upper, "Return upper light index.");
cls_Graphic3d_LightSet.def("IsEmpty", (Standard_Boolean (Graphic3d_LightSet::*)() const) &Graphic3d_LightSet::IsEmpty, "Return TRUE if lights list is empty.");
cls_Graphic3d_LightSet.def("Extent", (Standard_Integer (Graphic3d_LightSet::*)() const) &Graphic3d_LightSet::Extent, "Return number of light sources.");
cls_Graphic3d_LightSet.def("Value", (const opencascade::handle<Graphic3d_CLight> & (Graphic3d_LightSet::*)(Standard_Integer) const) &Graphic3d_LightSet::Value, "Return the light source for specified index within range [Lower(), Upper()].", py::arg("theIndex"));
cls_Graphic3d_LightSet.def("Contains", (Standard_Boolean (Graphic3d_LightSet::*)(const opencascade::handle<Graphic3d_CLight> &) const) &Graphic3d_LightSet::Contains, "Return TRUE if light source is defined in this set.", py::arg("theLight"));
cls_Graphic3d_LightSet.def("Add", (Standard_Boolean (Graphic3d_LightSet::*)(const opencascade::handle<Graphic3d_CLight> &)) &Graphic3d_LightSet::Add, "Append new light source.", py::arg("theLight"));
cls_Graphic3d_LightSet.def("Remove", (Standard_Boolean (Graphic3d_LightSet::*)(const opencascade::handle<Graphic3d_CLight> &)) &Graphic3d_LightSet::Remove, "Remove light source.", py::arg("theLight"));
cls_Graphic3d_LightSet.def("NbLightsOfType", (Standard_Integer (Graphic3d_LightSet::*)(Graphic3d_TypeOfLightSource) const) &Graphic3d_LightSet::NbLightsOfType, "Returns total amount of lights of specified type.", py::arg("theType"));
cls_Graphic3d_LightSet.def("UpdateRevision", (Standard_Size (Graphic3d_LightSet::*)()) &Graphic3d_LightSet::UpdateRevision, "Update light sources revision.");
cls_Graphic3d_LightSet.def("Revision", (Standard_Size (Graphic3d_LightSet::*)() const) &Graphic3d_LightSet::Revision, "Return light sources revision.");
cls_Graphic3d_LightSet.def("NbEnabled", (Standard_Integer (Graphic3d_LightSet::*)() const) &Graphic3d_LightSet::NbEnabled, "Returns total amount of enabled lights EXCLUDING ambient.");
cls_Graphic3d_LightSet.def("NbEnabledLightsOfType", (Standard_Integer (Graphic3d_LightSet::*)(Graphic3d_TypeOfLightSource) const) &Graphic3d_LightSet::NbEnabledLightsOfType, "Returns total amount of enabled lights of specified type.", py::arg("theType"));
cls_Graphic3d_LightSet.def("AmbientColor", (const Graphic3d_Vec4 & (Graphic3d_LightSet::*)() const) &Graphic3d_LightSet::AmbientColor, "Returns cumulative ambient color, which is computed as sum of all enabled ambient light sources. Values are NOT clamped (can be greater than 1.0f) and alpha component is fixed to 1.0f.");
cls_Graphic3d_LightSet.def("KeyEnabledLong", (const TCollection_AsciiString & (Graphic3d_LightSet::*)() const) &Graphic3d_LightSet::KeyEnabledLong, "Returns a string defining a list of enabled light sources as concatenation of letters 'd' (Directional), 'p' (Point), 's' (Spot) depending on the type of light source in the list. Example: 'dppp'.");
cls_Graphic3d_LightSet.def("KeyEnabledShort", (const TCollection_AsciiString & (Graphic3d_LightSet::*)() const) &Graphic3d_LightSet::KeyEnabledShort, "Returns a string defining a list of enabled light sources as concatenation of letters 'd' (Directional), 'p' (Point), 's' (Spot) depending on the type of light source in the list, specified only once. Example: 'dp'.");

// Enums
py::enum_<Graphic3d_LightSet::IterationFilter>(cls_Graphic3d_LightSet, "IterationFilter", "Iteration filter flags.")
	.value("IterationFilter_None", Graphic3d_LightSet::IterationFilter::IterationFilter_None)
	.value("IterationFilter_ExcludeAmbient", Graphic3d_LightSet::IterationFilter::IterationFilter_ExcludeAmbient)
	.value("IterationFilter_ExcludeDisabled", Graphic3d_LightSet::IterationFilter::IterationFilter_ExcludeDisabled)
	.value("IterationFilter_ExcludeDisabledAndAmbient", Graphic3d_LightSet::IterationFilter::IterationFilter_ExcludeDisabledAndAmbient)
	.export_values();

}