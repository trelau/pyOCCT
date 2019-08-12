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
#include <IGESData_IGESEntity.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IGESGraph_DrawingSize.hxx>
#include <Standard_Type.hxx>

void bind_IGESGraph_DrawingSize(py::module &mod){

py::class_<IGESGraph_DrawingSize, opencascade::handle<IGESGraph_DrawingSize>, IGESData_IGESEntity> cls_IGESGraph_DrawingSize(mod, "IGESGraph_DrawingSize", "defines IGESDrawingSize, Type <406> Form <16> in package IGESGraph");

// Constructors
cls_IGESGraph_DrawingSize.def(py::init<>());

// Fields

// Methods
cls_IGESGraph_DrawingSize.def("Init", (void (IGESGraph_DrawingSize::*)(const Standard_Integer, const Standard_Real, const Standard_Real)) &IGESGraph_DrawingSize::Init, "This method is used to set the fields of the class DrawingSize - nbProps : Number of property values (NP = 2) - aXSize : Extent of Drawing along positive XD axis - aYSize : Extent of Drawing along positive YD axis", py::arg("nbProps"), py::arg("aXSize"), py::arg("aYSize"));
cls_IGESGraph_DrawingSize.def("NbPropertyValues", (Standard_Integer (IGESGraph_DrawingSize::*)() const) &IGESGraph_DrawingSize::NbPropertyValues, "returns the number of property values in <me> (NP = 2)");
cls_IGESGraph_DrawingSize.def("XSize", (Standard_Real (IGESGraph_DrawingSize::*)() const) &IGESGraph_DrawingSize::XSize, "returns the extent of Drawing along positive XD axis");
cls_IGESGraph_DrawingSize.def("YSize", (Standard_Real (IGESGraph_DrawingSize::*)() const) &IGESGraph_DrawingSize::YSize, "returns the extent of Drawing along positive YD axis");
cls_IGESGraph_DrawingSize.def_static("get_type_name_", (const char * (*)()) &IGESGraph_DrawingSize::get_type_name, "None");
cls_IGESGraph_DrawingSize.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGraph_DrawingSize::get_type_descriptor, "None");
cls_IGESGraph_DrawingSize.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGraph_DrawingSize::*)() const) &IGESGraph_DrawingSize::DynamicType, "None");

// Enums

}