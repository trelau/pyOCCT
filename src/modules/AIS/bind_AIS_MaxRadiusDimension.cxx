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
#include <AIS_EllipseRadiusDimension.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_ExtendedString.hxx>
#include <gp_Pnt.hxx>
#include <DsgPrs_ArrowSide.hxx>
#include <Standard_Handle.hxx>
#include <Prs3d_Projector.hxx>
#include <Geom_Transformation.hxx>
#include <Prs3d_Presentation.hxx>
#include <AIS_MaxRadiusDimension.hxx>
#include <Standard_Type.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <SelectMgr_Selection.hxx>

void bind_AIS_MaxRadiusDimension(py::module &mod){

py::class_<AIS_MaxRadiusDimension, opencascade::handle<AIS_MaxRadiusDimension>, AIS_EllipseRadiusDimension> cls_AIS_MaxRadiusDimension(mod, "AIS_MaxRadiusDimension", "Ellipse Max radius dimension of a Shape which can be Edge or Face (planar or cylindrical(surface of extrusion or surface of offset))");

// Constructors
cls_AIS_MaxRadiusDimension.def(py::init<const TopoDS_Shape &, const Standard_Real, const TCollection_ExtendedString &>(), py::arg("aShape"), py::arg("aVal"), py::arg("aText"));
cls_AIS_MaxRadiusDimension.def(py::init<const TopoDS_Shape &, const Standard_Real, const TCollection_ExtendedString &, const gp_Pnt &, const DsgPrs_ArrowSide>(), py::arg("aShape"), py::arg("aVal"), py::arg("aText"), py::arg("aPosition"), py::arg("aSymbolPrs"));
cls_AIS_MaxRadiusDimension.def(py::init<const TopoDS_Shape &, const Standard_Real, const TCollection_ExtendedString &, const gp_Pnt &, const DsgPrs_ArrowSide, const Standard_Real>(), py::arg("aShape"), py::arg("aVal"), py::arg("aText"), py::arg("aPosition"), py::arg("aSymbolPrs"), py::arg("anArrowSize"));

// Fields

// Methods
cls_AIS_MaxRadiusDimension.def("Compute", (void (AIS_MaxRadiusDimension::*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Geom_Transformation> &, const opencascade::handle<Prs3d_Presentation> &)) &AIS_MaxRadiusDimension::Compute, "computes the presentation according to a point of view given by <aProjector>. To be Used when the associated degenerated Presentations have been transformed by <aTrsf> which is not a Pure Translation. The HLR Prs can't be deducted automatically WARNING :<aTrsf> must be applied to the object to display before computation !!!", py::arg("aProjector"), py::arg("aTrsf"), py::arg("aPresentation"));
cls_AIS_MaxRadiusDimension.def_static("get_type_name_", (const char * (*)()) &AIS_MaxRadiusDimension::get_type_name, "None");
cls_AIS_MaxRadiusDimension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_MaxRadiusDimension::get_type_descriptor, "None");
cls_AIS_MaxRadiusDimension.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_MaxRadiusDimension::*)() const) &AIS_MaxRadiusDimension::DynamicType, "None");

// Enums

}