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
#include <TopOpeBRepDS_Interference.hxx>
#include <TopOpeBRepDS_Transition.hxx>
#include <TopOpeBRepDS_Kind.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepDS_SolidSurfaceInterference.hxx>
#include <Standard_Type.hxx>

void bind_TopOpeBRepDS_SolidSurfaceInterference(py::module &mod){

py::class_<TopOpeBRepDS_SolidSurfaceInterference, opencascade::handle<TopOpeBRepDS_SolidSurfaceInterference>, TopOpeBRepDS_Interference> cls_TopOpeBRepDS_SolidSurfaceInterference(mod, "TopOpeBRepDS_SolidSurfaceInterference", "Interference");

// Constructors
cls_TopOpeBRepDS_SolidSurfaceInterference.def(py::init<const TopOpeBRepDS_Transition &, const TopOpeBRepDS_Kind, const Standard_Integer, const TopOpeBRepDS_Kind, const Standard_Integer>(), py::arg("Transition"), py::arg("SupportType"), py::arg("Support"), py::arg("GeometryType"), py::arg("Geometry"));

// Fields

// Methods
cls_TopOpeBRepDS_SolidSurfaceInterference.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepDS_SolidSurfaceInterference::get_type_name, "None");
cls_TopOpeBRepDS_SolidSurfaceInterference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepDS_SolidSurfaceInterference::get_type_descriptor, "None");
cls_TopOpeBRepDS_SolidSurfaceInterference.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepDS_SolidSurfaceInterference::*)() const) &TopOpeBRepDS_SolidSurfaceInterference::DynamicType, "None");

// Enums

}