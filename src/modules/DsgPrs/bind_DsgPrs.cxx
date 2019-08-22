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
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <Prs3d_Presentation.hxx>
#include <Prs3d_DimensionAspect.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <DsgPrs_ArrowSide.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pln.hxx>
#include <Geom_Surface.hxx>
#include <Geom_Curve.hxx>
#include <gp_Ax1.hxx>
#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <DsgPrs_EllipseRadiusPresentation.hxx>
#include <DsgPrs_LengthPresentation.hxx>
#include <DsgPrs_RadiusPresentation.hxx>
#include <DsgPrs_DiameterPresentation.hxx>
#include <DsgPrs_FilletRadiusPresentation.hxx>
#include <DsgPrs_AnglePresentation.hxx>
#include <DsgPrs_Chamf2dPresentation.hxx>
#include <DsgPrs_ParalPresentation.hxx>
#include <DsgPrs_PerpenPresentation.hxx>
#include <DsgPrs_SymmetricPresentation.hxx>
#include <DsgPrs_MidPointPresentation.hxx>
#include <DsgPrs_TangentPresentation.hxx>
#include <DsgPrs_ConcentricPresentation.hxx>
#include <DsgPrs_FixPresentation.hxx>
#include <DsgPrs_IdenticPresentation.hxx>
#include <DsgPrs_EqualRadiusPresentation.hxx>
#include <DsgPrs_EqualDistancePresentation.hxx>
#include <DsgPrs_SymbPresentation.hxx>
#include <DsgPrs_ShapeDirPresentation.hxx>
#include <DsgPrs_OffsetPresentation.hxx>
#include <DsgPrs_XYZAxisPresentation.hxx>
#include <DsgPrs_XYZPlanePresentation.hxx>
#include <DsgPrs_ShadedPlanePresentation.hxx>
#include <DsgPrs.hxx>

void bind_DsgPrs(py::module &mod){

py::class_<DsgPrs> cls_DsgPrs(mod, "DsgPrs", "Describes Standard Presentations for DsgIHM objects");

// Constructors

// Fields

// Methods
// cls_DsgPrs.def_static("operator new_", (void * (*)(size_t)) &DsgPrs::operator new, "None", py::arg("theSize"));
// cls_DsgPrs.def_static("operator delete_", (void (*)(void *)) &DsgPrs::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs.def_static("ComputeSymbol_", [](const opencascade::handle<Prs3d_Presentation> & a0, const opencascade::handle<Prs3d_DimensionAspect> & a1, const gp_Pnt & a2, const gp_Pnt & a3, const gp_Dir & a4, const gp_Dir & a5, const DsgPrs_ArrowSide a6) -> void { return DsgPrs::ComputeSymbol(a0, a1, a2, a3, a4, a5, a6); });
cls_DsgPrs.def_static("ComputeSymbol_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_DimensionAspect> &, const gp_Pnt &, const gp_Pnt &, const gp_Dir &, const gp_Dir &, const DsgPrs_ArrowSide, const Standard_Boolean)) &DsgPrs::ComputeSymbol, "draws symbols ((one or two) arrows,(one or two)points at thebeginning and at the end of the dimension", py::arg("aPresentation"), py::arg("anAspect"), py::arg("pt1"), py::arg("pt2"), py::arg("dir1"), py::arg("dir2"), py::arg("ArrowSide"), py::arg("drawFromCenter"));
cls_DsgPrs.def_static("ComputePlanarFacesLengthPresentation_", (void (*)(const Standard_Real, const Standard_Real, const gp_Pnt &, const gp_Pnt &, const gp_Dir &, const gp_Pnt &, const gp_Pln &, gp_Pnt &, gp_Pnt &, gp_Dir &)) &DsgPrs::ComputePlanarFacesLengthPresentation, "None", py::arg("FirstArrowLength"), py::arg("SecondArrowLength"), py::arg("AttachmentPoint1"), py::arg("AttachmentPoint2"), py::arg("DirAttach"), py::arg("OffsetPoint"), py::arg("PlaneOfFaces"), py::arg("EndOfArrow1"), py::arg("EndOfArrow2"), py::arg("DirOfArrow1"));
cls_DsgPrs.def_static("ComputeCurvilinearFacesLengthPresentation_", [](const Standard_Real FirstArrowLength, const Standard_Real SecondArrowLength, const opencascade::handle<Geom_Surface> & SecondSurf, const gp_Pnt & AttachmentPoint1, const gp_Pnt & AttachmentPoint2, const gp_Dir & DirAttach, gp_Pnt & EndOfArrow2, gp_Dir & DirOfArrow1, opencascade::handle<Geom_Curve> & VCurve, opencascade::handle<Geom_Curve> & UCurve, Standard_Real & FirstU, Standard_Real & deltaU, Standard_Real & FirstV, Standard_Real & deltaV){ DsgPrs::ComputeCurvilinearFacesLengthPresentation(FirstArrowLength, SecondArrowLength, SecondSurf, AttachmentPoint1, AttachmentPoint2, DirAttach, EndOfArrow2, DirOfArrow1, VCurve, UCurve, FirstU, deltaU, FirstV, deltaV); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(FirstU, deltaU, FirstV, deltaV); }, "None", py::arg("FirstArrowLength"), py::arg("SecondArrowLength"), py::arg("SecondSurf"), py::arg("AttachmentPoint1"), py::arg("AttachmentPoint2"), py::arg("DirAttach"), py::arg("EndOfArrow2"), py::arg("DirOfArrow1"), py::arg("VCurve"), py::arg("UCurve"), py::arg("FirstU"), py::arg("deltaU"), py::arg("FirstV"), py::arg("deltaV"));
cls_DsgPrs.def_static("ComputeFacesAnglePresentation_", [](const Standard_Real ArrowLength, const Standard_Real Value, const gp_Pnt & CenterPoint, const gp_Pnt & AttachmentPoint1, const gp_Pnt & AttachmentPoint2, const gp_Dir & dir1, const gp_Dir & dir2, const gp_Dir & axisdir, const Standard_Boolean isPlane, const gp_Ax1 & AxisOfSurf, const gp_Pnt & OffsetPoint, gp_Circ & AngleCirc, Standard_Real & FirstParAngleCirc, Standard_Real & LastParAngleCirc, gp_Pnt & EndOfArrow1, gp_Pnt & EndOfArrow2, gp_Dir & DirOfArrow1, gp_Dir & DirOfArrow2, gp_Pnt & ProjAttachPoint2, gp_Circ & AttachCirc, Standard_Real & FirstParAttachCirc, Standard_Real & LastParAttachCirc){ DsgPrs::ComputeFacesAnglePresentation(ArrowLength, Value, CenterPoint, AttachmentPoint1, AttachmentPoint2, dir1, dir2, axisdir, isPlane, AxisOfSurf, OffsetPoint, AngleCirc, FirstParAngleCirc, LastParAngleCirc, EndOfArrow1, EndOfArrow2, DirOfArrow1, DirOfArrow2, ProjAttachPoint2, AttachCirc, FirstParAttachCirc, LastParAttachCirc); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(FirstParAngleCirc, LastParAngleCirc, FirstParAttachCirc, LastParAttachCirc); }, "None", py::arg("ArrowLength"), py::arg("Value"), py::arg("CenterPoint"), py::arg("AttachmentPoint1"), py::arg("AttachmentPoint2"), py::arg("dir1"), py::arg("dir2"), py::arg("axisdir"), py::arg("isPlane"), py::arg("AxisOfSurf"), py::arg("OffsetPoint"), py::arg("AngleCirc"), py::arg("FirstParAngleCirc"), py::arg("LastParAngleCirc"), py::arg("EndOfArrow1"), py::arg("EndOfArrow2"), py::arg("DirOfArrow1"), py::arg("DirOfArrow2"), py::arg("ProjAttachPoint2"), py::arg("AttachCirc"), py::arg("FirstParAttachCirc"), py::arg("LastParAttachCirc"));
cls_DsgPrs.def_static("ComputeRadiusLine_", (void (*)(const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const Standard_Boolean, gp_Pnt &, gp_Pnt &)) &DsgPrs::ComputeRadiusLine, "None", py::arg("aCenter"), py::arg("anEndOfArrow"), py::arg("aPosition"), py::arg("drawFromCenter"), py::arg("aRadLineOrign"), py::arg("aRadLineEnd"));
cls_DsgPrs.def_static("ComputeFilletRadiusPresentation_", [](const Standard_Real ArrowLength, const Standard_Real Value, const gp_Pnt & Position, const gp_Dir & NormalDir, const gp_Pnt & FirstPoint, const gp_Pnt & SecondPoint, const gp_Pnt & Center, const gp_Pnt & BasePnt, const Standard_Boolean drawRevers, Standard_Boolean & SpecCase, gp_Circ & FilletCirc, Standard_Real & FirstParCirc, Standard_Real & LastParCirc, gp_Pnt & EndOfArrow, gp_Dir & DirOfArrow, gp_Pnt & DrawPosition){ DsgPrs::ComputeFilletRadiusPresentation(ArrowLength, Value, Position, NormalDir, FirstPoint, SecondPoint, Center, BasePnt, drawRevers, SpecCase, FilletCirc, FirstParCirc, LastParCirc, EndOfArrow, DirOfArrow, DrawPosition); return std::tuple<Standard_Boolean &, Standard_Real &, Standard_Real &>(SpecCase, FirstParCirc, LastParCirc); }, "computes Geometry for fillet radius presentation; special case flag SpecCase equal Standard_True if radius of fillet circle = 0 or if anngle between Vec1(Center, FirstPoint) and Vec2(Center,SecondPoint) equal 0 or PI", py::arg("ArrowLength"), py::arg("Value"), py::arg("Position"), py::arg("NormalDir"), py::arg("FirstPoint"), py::arg("SecondPoint"), py::arg("Center"), py::arg("BasePnt"), py::arg("drawRevers"), py::arg("SpecCase"), py::arg("FilletCirc"), py::arg("FirstParCirc"), py::arg("LastParCirc"), py::arg("EndOfArrow"), py::arg("DirOfArrow"), py::arg("DrawPosition"));
cls_DsgPrs.def_static("DistanceFromApex_", (Standard_Real (*)(const gp_Elips &, const gp_Pnt &, const Standard_Real)) &DsgPrs::DistanceFromApex, "computes length of ellipse arc in parametric units", py::arg("elips"), py::arg("Apex"), py::arg("par"));

// Enums

}