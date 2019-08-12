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
#include <OpenGl_Resource.hxx>
#include <OpenGl_Context.hxx>
#include <NCollection_SparseArrayBase.hxx>
#include <Standard_Handle.hxx>
#include <Graphic3d_HatchStyle.hxx>
#include <OpenGl_LineAttributes.hxx>
#include <Standard_Type.hxx>

void bind_OpenGl_LineAttributes(py::module &mod){

/*
py::class_<OpenGl_LineAttributes, opencascade::handle<OpenGl_LineAttributes>, OpenGl_Resource> cls_OpenGl_LineAttributes(mod, "OpenGl_LineAttributes", "Utility class to manage OpenGL state of polygon hatching rasterization and keeping its cached state. The hatching rasterization is implemented using glPolygonStipple function of OpenGL. State of hatching is controlled by two parameters - type of hatching and IsEnabled parameter. The hatching rasterization is enabled only if non-zero index pattern type is selected (zero by default is reserved for solid filling) and if IsEnabled flag is set to true. The IsEnabled parameter is useful for temporarily turning on/off the hatching rasterization without making any costly GL calls for changing the hatch pattern. This is a sharable resource class - it creates OpenGL context objects for each hatch pattern to achieve quicker switching between them, thesse GL objects are freed when the resource is released by owner context.");

// Constructors
cls_OpenGl_LineAttributes.def(py::init<>());

// Fields

// Methods
cls_OpenGl_LineAttributes.def("Release", (void (OpenGl_LineAttributes::*)(OpenGl_Context *)) &OpenGl_LineAttributes::Release, "Release GL resources.", py::arg("theGlCtx"));
cls_OpenGl_LineAttributes.def("EstimatedDataSize", (Standard_Size (OpenGl_LineAttributes::*)() const) &OpenGl_LineAttributes::EstimatedDataSize, "Returns estimated GPU memory usage - not implemented.");
cls_OpenGl_LineAttributes.def("TypeOfHatch", (int (OpenGl_LineAttributes::*)() const) &OpenGl_LineAttributes::TypeOfHatch, "Index of currently selected type of hatch.");
cls_OpenGl_LineAttributes.def("SetTypeOfHatch", (int (OpenGl_LineAttributes::*)(const OpenGl_Context *, const opencascade::handle<Graphic3d_HatchStyle> &)) &OpenGl_LineAttributes::SetTypeOfHatch, "Sets type of the hatch.", py::arg("theGlCtx"), py::arg("theStyle"));
cls_OpenGl_LineAttributes.def("IsEnabled", (bool (OpenGl_LineAttributes::*)() const) &OpenGl_LineAttributes::IsEnabled, "Current enabled state of the hatching rasterization.");
cls_OpenGl_LineAttributes.def("SetEnabled", (bool (OpenGl_LineAttributes::*)(const OpenGl_Context *, const bool)) &OpenGl_LineAttributes::SetEnabled, "Turns on/off the hatching rasterization rasterization.", py::arg("theGlCtx"), py::arg("theToEnable"));
cls_OpenGl_LineAttributes.def_static("get_type_name_", (const char * (*)()) &OpenGl_LineAttributes::get_type_name, "None");
cls_OpenGl_LineAttributes.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_LineAttributes::get_type_descriptor, "None");
cls_OpenGl_LineAttributes.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_LineAttributes::*)() const) &OpenGl_LineAttributes::DynamicType, "None");

// Enums
*/

}