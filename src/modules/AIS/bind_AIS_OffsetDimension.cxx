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
#include <AIS_Relation.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_ExtendedString.hxx>
#include <Standard_Handle.hxx>
#include <Prs3d_Projector.hxx>
#include <Geom_Transformation.hxx>
#include <Prs3d_Presentation.hxx>
#include <AIS_KindOfDimension.hxx>
#include <gp_Trsf.hxx>
#include <AIS_OffsetDimension.hxx>
#include <Standard_Type.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <SelectMgr_Selection.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>

void bind_AIS_OffsetDimension(py::module &mod){

py::class_<AIS_OffsetDimension, opencascade::handle<AIS_OffsetDimension>, AIS_Relation> cls_AIS_OffsetDimension(mod, "AIS_OffsetDimension", "A framework to display dimensions of offsets. The relation between the offset and the basis shape is indicated. This relation is displayed with arrows and text. The text gives the dsitance between the offset and the basis shape.");

// Constructors
cls_AIS_OffsetDimension.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Real, const TCollection_ExtendedString &>(), py::arg("FistShape"), py::arg("SecondShape"), py::arg("aVal"), py::arg("aText"));

// Fields

// Methods
cls_AIS_OffsetDimension.def("Compute", (void (AIS_OffsetDimension::*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Geom_Transformation> &, const opencascade::handle<Prs3d_Presentation> &)) &AIS_OffsetDimension::Compute, "computes the presentation according to a point of view given by <aProjector>. To be Used when the associated degenerated Presentations have been transformed by <aTrsf> which is not a Pure Translation. The HLR Prs can't be deducted automatically WARNING :<aTrsf> must be applied to the object to display before computation !!!", py::arg("aProjector"), py::arg("aTrsf"), py::arg("aPresentation"));
cls_AIS_OffsetDimension.def("KindOfDimension", (AIS_KindOfDimension (AIS_OffsetDimension::*)() const) &AIS_OffsetDimension::KindOfDimension, "Indicates that the dimension we are concerned with is an offset.");
cls_AIS_OffsetDimension.def("IsMovable", (Standard_Boolean (AIS_OffsetDimension::*)() const) &AIS_OffsetDimension::IsMovable, "Returns true if the offset datum is movable.");
cls_AIS_OffsetDimension.def("SetRelativePos", (void (AIS_OffsetDimension::*)(const gp_Trsf &)) &AIS_OffsetDimension::SetRelativePos, "Sets a transformation aTrsf for presentation and selection to a relative position.", py::arg("aTrsf"));
cls_AIS_OffsetDimension.def_static("get_type_name_", (const char * (*)()) &AIS_OffsetDimension::get_type_name, "None");
cls_AIS_OffsetDimension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_OffsetDimension::get_type_descriptor, "None");
cls_AIS_OffsetDimension.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_OffsetDimension::*)() const) &AIS_OffsetDimension::DynamicType, "None");

// Enums

}