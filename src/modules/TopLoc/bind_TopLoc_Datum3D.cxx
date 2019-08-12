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
#include <gp_Trsf.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Handle.hxx>
#include <TopLoc_Datum3D.hxx>
#include <Standard_Type.hxx>

void bind_TopLoc_Datum3D(py::module &mod){

py::class_<TopLoc_Datum3D, opencascade::handle<TopLoc_Datum3D>, Standard_Transient> cls_TopLoc_Datum3D(mod, "TopLoc_Datum3D", "Describes a coordinate transformation, i.e. a change to an elementary 3D coordinate system, or position in 3D space. A Datum3D is always described relative to the default datum. The default datum is described relative to itself: its origin is (0,0,0), and its axes are (1,0,0) (0,1,0) (0,0,1).");

// Constructors
cls_TopLoc_Datum3D.def(py::init<>());
cls_TopLoc_Datum3D.def(py::init<const gp_Trsf &>(), py::arg("T"));

// Fields

// Methods
cls_TopLoc_Datum3D.def("Transformation", (const gp_Trsf & (TopLoc_Datum3D::*)() const) &TopLoc_Datum3D::Transformation, "Returns a gp_Trsf which, when applied to this datum, produces the default datum.");
cls_TopLoc_Datum3D.def("ShallowDump", (void (TopLoc_Datum3D::*)(Standard_OStream &) const) &TopLoc_Datum3D::ShallowDump, "Writes the contents of this Datum3D to the stream S.", py::arg("S"));
cls_TopLoc_Datum3D.def_static("get_type_name_", (const char * (*)()) &TopLoc_Datum3D::get_type_name, "None");
cls_TopLoc_Datum3D.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopLoc_Datum3D::get_type_descriptor, "None");
cls_TopLoc_Datum3D.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopLoc_Datum3D::*)() const) &TopLoc_Datum3D::DynamicType, "None");

// Enums

}