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
#include <DsgPrs_ArrowSide.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <PrsMgr_PresentationManager.hxx>
#include <Prs3d_DimensionAspect.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pln.hxx>
#include <Geom_Surface.hxx>
#include <Geom_Curve.hxx>
#include <gp_Ax1.hxx>
#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <DsgPrs.hxx>
#include <Prs3d_Drawer.hxx>
#include <TCollection_ExtendedString.hxx>
#include <DsgPrs_AnglePresentation.hxx>
#include <DsgPrs_Chamf2dPresentation.hxx>
#include <DsgPrs_ConcentricPresentation.hxx>
#include <Prs3d_Root.hxx>
#include <gp_Ax2.hxx>
#include <DsgPrs_DatumPrs.hxx>
#include <DsgPrs_DiameterPresentation.hxx>
#include <Geom_OffsetCurve.hxx>
#include <DsgPrs_EllipseRadiusPresentation.hxx>
#include <Geom_Plane.hxx>
#include <DsgPrs_EqualDistancePresentation.hxx>
#include <DsgPrs_EqualRadiusPresentation.hxx>
#include <Geom_TrimmedCurve.hxx>
#include <DsgPrs_FilletRadiusPresentation.hxx>
#include <DsgPrs_FixPresentation.hxx>
#include <DsgPrs_IdenticPresentation.hxx>
#include <DsgPrs_LengthPresentation.hxx>
#include <DsgPrs_MidPointPresentation.hxx>
#include <DsgPrs_OffsetPresentation.hxx>
#include <DsgPrs_ParalPresentation.hxx>
#include <DsgPrs_PerpenPresentation.hxx>
#include <DsgPrs_RadiusPresentation.hxx>
#include <DsgPrs_ShadedPlanePresentation.hxx>
#include <TopoDS_Shape.hxx>
#include <DsgPrs_ShapeDirPresentation.hxx>
#include <DsgPrs_SymbPresentation.hxx>
#include <gp_Lin.hxx>
#include <DsgPrs_SymmetricPresentation.hxx>
#include <DsgPrs_TangentPresentation.hxx>
#include <Prs3d_LineAspect.hxx>
#include <Prs3d_ArrowAspect.hxx>
#include <Prs3d_TextAspect.hxx>
#include <DsgPrs_XYZAxisPresentation.hxx>
#include <DsgPrs_XYZPlanePresentation.hxx>

PYBIND11_MODULE(DsgPrs, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.PrsMgr");
py::module::import("OCCT.Prs3d");
py::module::import("OCCT.gp");
py::module::import("OCCT.Geom");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.TopoDS");

// ENUM: DSGPRS_ARROWSIDE
py::enum_<DsgPrs_ArrowSide>(mod, "DsgPrs_ArrowSide", "Designates how many arrows will be displayed and where they will be displayed in presenting a length.")
	.value("DsgPrs_AS_NONE", DsgPrs_ArrowSide::DsgPrs_AS_NONE)
	.value("DsgPrs_AS_FIRSTAR", DsgPrs_ArrowSide::DsgPrs_AS_FIRSTAR)
	.value("DsgPrs_AS_LASTAR", DsgPrs_ArrowSide::DsgPrs_AS_LASTAR)
	.value("DsgPrs_AS_BOTHAR", DsgPrs_ArrowSide::DsgPrs_AS_BOTHAR)
	.value("DsgPrs_AS_FIRSTPT", DsgPrs_ArrowSide::DsgPrs_AS_FIRSTPT)
	.value("DsgPrs_AS_LASTPT", DsgPrs_ArrowSide::DsgPrs_AS_LASTPT)
	.value("DsgPrs_AS_BOTHPT", DsgPrs_ArrowSide::DsgPrs_AS_BOTHPT)
	.value("DsgPrs_AS_FIRSTAR_LASTPT", DsgPrs_ArrowSide::DsgPrs_AS_FIRSTAR_LASTPT)
	.value("DsgPrs_AS_FIRSTPT_LASTAR", DsgPrs_ArrowSide::DsgPrs_AS_FIRSTPT_LASTAR)
	.export_values();


// CLASS: DSGPRS
py::class_<DsgPrs> cls_DsgPrs(mod, "DsgPrs", "Describes Standard Presentations for DsgIHM objects");

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

// CLASS: DSGPRS_ANGLEPRESENTATION
py::class_<DsgPrs_AnglePresentation> cls_DsgPrs_AnglePresentation(mod, "DsgPrs_AnglePresentation", "A framework for displaying angles.");

// Methods
// cls_DsgPrs_AnglePresentation.def_static("operator new_", (void * (*)(size_t)) &DsgPrs_AnglePresentation::operator new, "None", py::arg("theSize"));
// cls_DsgPrs_AnglePresentation.def_static("operator delete_", (void (*)(void *)) &DsgPrs_AnglePresentation::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs_AnglePresentation.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs_AnglePresentation::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs_AnglePresentation.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs_AnglePresentation::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs_AnglePresentation.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs_AnglePresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs_AnglePresentation.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs_AnglePresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs_AnglePresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Real, const TCollection_ExtendedString &, const gp_Circ &, const gp_Pnt &, const gp_Pnt &, const gp_Circ &, const gp_Circ &, const Standard_Real)) &DsgPrs_AnglePresentation::Add, "Draws the presenation of the full angle of a cone. VminCircle - a circle at V parameter = Vmin VmaxCircle - a circle at V parameter = Vmax aCircle - a circle at V parameter from projection of aPosition to axis of the cone", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aVal"), py::arg("aText"), py::arg("aCircle"), py::arg("aPosition"), py::arg("Apex"), py::arg("VminCircle"), py::arg("VmaxCircle"), py::arg("aArrowSize"));
cls_DsgPrs_AnglePresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Real, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Dir &, const gp_Dir &, const gp_Pnt &)) &DsgPrs_AnglePresentation::Add, "Draws the representation of the angle defined by dir1 and dir2, centered on CenterPoint, using the offset point OffsetPoint. Lines are drawn to points AttachmentPoint1 and AttachmentPoint2", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("theval"), py::arg("CenterPoint"), py::arg("AttachmentPoint1"), py::arg("AttachmentPoint2"), py::arg("dir1"), py::arg("dir2"), py::arg("OffsetPoint"));
cls_DsgPrs_AnglePresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Real, const TCollection_ExtendedString &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Dir &, const gp_Dir &, const gp_Pnt &)) &DsgPrs_AnglePresentation::Add, "Same as above, but <thevalstring> contains conversion in Session units....", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("theval"), py::arg("thevalstring"), py::arg("CenterPoint"), py::arg("AttachmentPoint1"), py::arg("AttachmentPoint2"), py::arg("dir1"), py::arg("dir2"), py::arg("OffsetPoint"));
cls_DsgPrs_AnglePresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Real, const TCollection_ExtendedString &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Dir &, const gp_Dir &, const gp_Pnt &, const DsgPrs_ArrowSide)) &DsgPrs_AnglePresentation::Add, "Same as above, may add one or two Arrows according to <ArrowSide> value", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("theval"), py::arg("thevalstring"), py::arg("CenterPoint"), py::arg("AttachmentPoint1"), py::arg("AttachmentPoint2"), py::arg("dir1"), py::arg("dir2"), py::arg("OffsetPoint"), py::arg("ArrowSide"));
cls_DsgPrs_AnglePresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Real, const TCollection_ExtendedString &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Dir &, const gp_Dir &, const gp_Dir &, const gp_Pnt &)) &DsgPrs_AnglePresentation::Add, "Same as above, but axisdir contains the axis direction useful for Revol that can be opened with 180 degrees", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("theval"), py::arg("thevalstring"), py::arg("CenterPoint"), py::arg("AttachmentPoint1"), py::arg("AttachmentPoint2"), py::arg("dir1"), py::arg("dir2"), py::arg("axisdir"), py::arg("OffsetPoint"));
cls_DsgPrs_AnglePresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Real, const TCollection_ExtendedString &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Dir &, const gp_Dir &, const gp_Dir &, const Standard_Boolean, const gp_Ax1 &, const gp_Pnt &, const DsgPrs_ArrowSide)) &DsgPrs_AnglePresentation::Add, "Same as above,may add one or two Arrows according to <ArrowSide> value", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("theval"), py::arg("thevalstring"), py::arg("CenterPoint"), py::arg("AttachmentPoint1"), py::arg("AttachmentPoint2"), py::arg("dir1"), py::arg("dir2"), py::arg("axisdir"), py::arg("isPlane"), py::arg("AxisOfSurf"), py::arg("OffsetPoint"), py::arg("ArrowSide"));
cls_DsgPrs_AnglePresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Real, const gp_Pnt &, const gp_Pnt &, const gp_Ax1 &, const DsgPrs_ArrowSide)) &DsgPrs_AnglePresentation::Add, "simple representation of a poor lonesome angle dimension Draw a line from <theCenter> to <AttachmentPoint1>, then operates a rotation around the perpmay add one or two Arrows according to <ArrowSide> value. The attributes (color,arrowsize,...) are driven by the Drawer.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("theval"), py::arg("theCenter"), py::arg("AttachmentPoint1"), py::arg("theAxe"), py::arg("ArrowSide"));

// CLASS: DSGPRS_CHAMF2DPRESENTATION
py::class_<DsgPrs_Chamf2dPresentation> cls_DsgPrs_Chamf2dPresentation(mod, "DsgPrs_Chamf2dPresentation", "Framework for display of 2D chamfers.");

// Methods
// cls_DsgPrs_Chamf2dPresentation.def_static("operator new_", (void * (*)(size_t)) &DsgPrs_Chamf2dPresentation::operator new, "None", py::arg("theSize"));
// cls_DsgPrs_Chamf2dPresentation.def_static("operator delete_", (void (*)(void *)) &DsgPrs_Chamf2dPresentation::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs_Chamf2dPresentation.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs_Chamf2dPresentation::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs_Chamf2dPresentation.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs_Chamf2dPresentation::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs_Chamf2dPresentation.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs_Chamf2dPresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs_Chamf2dPresentation.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs_Chamf2dPresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs_Chamf2dPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const gp_Pnt &, const gp_Pnt &, const TCollection_ExtendedString &)) &DsgPrs_Chamf2dPresentation::Add, "Defines the display of elements showing 2D chamfers on shapes. These include the text aText, the point of attachment, aPntAttach and the end point aPntEnd. These arguments are added to the presentation object aPresentation. Their display attributes are defined by the attribute manager aDrawer.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aPntAttach"), py::arg("aPntEnd"), py::arg("aText"));
cls_DsgPrs_Chamf2dPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const gp_Pnt &, const gp_Pnt &, const TCollection_ExtendedString &, const DsgPrs_ArrowSide)) &DsgPrs_Chamf2dPresentation::Add, "Defines the display of texts, symbols and icons used to present 2D chamfers. These include the text aText, the point of attachment, aPntAttach and the end point aPntEnd. These arguments are added to the presentation object aPresentation. Their display attributes are defined by the attribute manager aDrawer. The arrow at the point of attachment has a display defined by a value of the enumeration DsgPrs_Arrowside.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aPntAttach"), py::arg("aPntEnd"), py::arg("aText"), py::arg("ArrowSide"));

// CLASS: DSGPRS_CONCENTRICPRESENTATION
py::class_<DsgPrs_ConcentricPresentation> cls_DsgPrs_ConcentricPresentation(mod, "DsgPrs_ConcentricPresentation", "A framework to define display of relations of concentricity.");

// Methods
// cls_DsgPrs_ConcentricPresentation.def_static("operator new_", (void * (*)(size_t)) &DsgPrs_ConcentricPresentation::operator new, "None", py::arg("theSize"));
// cls_DsgPrs_ConcentricPresentation.def_static("operator delete_", (void (*)(void *)) &DsgPrs_ConcentricPresentation::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs_ConcentricPresentation.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs_ConcentricPresentation::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs_ConcentricPresentation.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs_ConcentricPresentation::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs_ConcentricPresentation.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs_ConcentricPresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs_ConcentricPresentation.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs_ConcentricPresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs_ConcentricPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const gp_Pnt &, const Standard_Real, const gp_Dir &, const gp_Pnt &)) &DsgPrs_ConcentricPresentation::Add, "Defines the display of elements showing relations of concentricity between shapes. These include the center aCenter, the radius aRadius, the direction aNorm and the point aPoint. These arguments are added to the presentation object aPresentation. Their display attributes are defined by the attribute manager aDrawer.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aCenter"), py::arg("aRadius"), py::arg("aNorm"), py::arg("aPoint"));

// CLASS: DSGPRS_DATUMPRS
py::class_<DsgPrs_DatumPrs, Prs3d_Root> cls_DsgPrs_DatumPrs(mod, "DsgPrs_DatumPrs", "A framework for displaying an XYZ trihedron.");

// Methods
// cls_DsgPrs_DatumPrs.def_static("operator new_", (void * (*)(size_t)) &DsgPrs_DatumPrs::operator new, "None", py::arg("theSize"));
// cls_DsgPrs_DatumPrs.def_static("operator delete_", (void (*)(void *)) &DsgPrs_DatumPrs::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs_DatumPrs.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs_DatumPrs::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs_DatumPrs.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs_DatumPrs::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs_DatumPrs.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs_DatumPrs::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs_DatumPrs.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs_DatumPrs::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs_DatumPrs.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const gp_Ax2 &, const opencascade::handle<Prs3d_Drawer> &)) &DsgPrs_DatumPrs::Add, "Draw XYZ axes at specified location with attributes defined by the attribute manager theDrawer: - Prs3d_DatumAspect defines arrow, line and lenght trihedron axis parameters, - Prs3d_TextAspect defines displayed text. The thihedron origin and axis directions are defined by theDatum coordinate system. DsgPrs_XYZAxisPresentation framework is used to create graphical primitives for each axis. Axes are marked with 'X', 'Y', 'Z' text.", py::arg("thePresentation"), py::arg("theDatum"), py::arg("theDrawer"));

// CLASS: DSGPRS_DIAMETERPRESENTATION
py::class_<DsgPrs_DiameterPresentation> cls_DsgPrs_DiameterPresentation(mod, "DsgPrs_DiameterPresentation", "A framework for displaying diameters in shapes.");

// Methods
// cls_DsgPrs_DiameterPresentation.def_static("operator new_", (void * (*)(size_t)) &DsgPrs_DiameterPresentation::operator new, "None", py::arg("theSize"));
// cls_DsgPrs_DiameterPresentation.def_static("operator delete_", (void (*)(void *)) &DsgPrs_DiameterPresentation::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs_DiameterPresentation.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs_DiameterPresentation::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs_DiameterPresentation.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs_DiameterPresentation::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs_DiameterPresentation.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs_DiameterPresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs_DiameterPresentation.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs_DiameterPresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs_DiameterPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TCollection_ExtendedString &, const gp_Pnt &, const gp_Circ &, const DsgPrs_ArrowSide, const Standard_Boolean)) &DsgPrs_DiameterPresentation::Add, "Draws the diameter of the circle aCircle displayed in the presentation aPresentation and with attributes defined by the attribute manager aDrawer. The point AttachmentPoint defines the point of contact between the circle and the diameter presentation. The value of the enumeration ArrowSide controls whether arrows will be displayed at either or both ends of the length. The text aText labels the diameter.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aText"), py::arg("AttachmentPoint"), py::arg("aCircle"), py::arg("ArrowSide"), py::arg("IsDiamSymbol"));
cls_DsgPrs_DiameterPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TCollection_ExtendedString &, const gp_Pnt &, const gp_Circ &, const Standard_Real, const Standard_Real, const DsgPrs_ArrowSide, const Standard_Boolean)) &DsgPrs_DiameterPresentation::Add, "Draws the diameter of the arc anArc displayed in the presentation aPresentation and with attributes defined by the attribute manager aDrawer. The point AttachmentPoint defines the point of contact between the arc and the diameter presentation. The value of the enumeration ArrowSide controls whether arrows will be displayed at either or both ends of the length. The parameters uFirst and uLast define the first and last points of the arc. The text aText labels the diameter.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aText"), py::arg("AttachmentPoint"), py::arg("aCircle"), py::arg("uFirst"), py::arg("uLast"), py::arg("ArrowSide"), py::arg("IsDiamSymbol"));

// CLASS: DSGPRS_ELLIPSERADIUSPRESENTATION
py::class_<DsgPrs_EllipseRadiusPresentation> cls_DsgPrs_EllipseRadiusPresentation(mod, "DsgPrs_EllipseRadiusPresentation", "None");

// Methods
// cls_DsgPrs_EllipseRadiusPresentation.def_static("operator new_", (void * (*)(size_t)) &DsgPrs_EllipseRadiusPresentation::operator new, "None", py::arg("theSize"));
// cls_DsgPrs_EllipseRadiusPresentation.def_static("operator delete_", (void (*)(void *)) &DsgPrs_EllipseRadiusPresentation::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs_EllipseRadiusPresentation.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs_EllipseRadiusPresentation::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs_EllipseRadiusPresentation.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs_EllipseRadiusPresentation::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs_EllipseRadiusPresentation.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs_EllipseRadiusPresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs_EllipseRadiusPresentation.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs_EllipseRadiusPresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs_EllipseRadiusPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Real, const TCollection_ExtendedString &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const Standard_Boolean, const DsgPrs_ArrowSide)) &DsgPrs_EllipseRadiusPresentation::Add, "draws a Radius (Major or Minor) representation for whole ellipse case", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("theval"), py::arg("aText"), py::arg("AttachmentPoint"), py::arg("anEndOfArrow"), py::arg("aCenter"), py::arg("IsMaxRadius"), py::arg("ArrowSide"));
cls_DsgPrs_EllipseRadiusPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Real, const TCollection_ExtendedString &, const gp_Elips &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const DsgPrs_ArrowSide)) &DsgPrs_EllipseRadiusPresentation::Add, "draws a Radius (Major or Minor) representation for arc of an ellipse case", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("theval"), py::arg("aText"), py::arg("anEllipse"), py::arg("AttachmentPoint"), py::arg("anEndOfArrow"), py::arg("aCenter"), py::arg("uFirst"), py::arg("IsInDomain"), py::arg("IsMaxRadius"), py::arg("ArrowSide"));
cls_DsgPrs_EllipseRadiusPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Real, const TCollection_ExtendedString &, const opencascade::handle<Geom_OffsetCurve> &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const DsgPrs_ArrowSide)) &DsgPrs_EllipseRadiusPresentation::Add, "draws a Radius (Major or Minor) representation for arc of an offset curve from ellipse", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("theval"), py::arg("aText"), py::arg("aCurve"), py::arg("AttachmentPoint"), py::arg("anEndOfArrow"), py::arg("aCenter"), py::arg("uFirst"), py::arg("IsInDomain"), py::arg("IsMaxRadius"), py::arg("ArrowSide"));

// CLASS: DSGPRS_EQUALDISTANCEPRESENTATION
py::class_<DsgPrs_EqualDistancePresentation> cls_DsgPrs_EqualDistancePresentation(mod, "DsgPrs_EqualDistancePresentation", "A framework to display equal distances between shapes and a given plane. The distance is the length of a projection from the shape to the plane. These distances are used to compare two shapes by this vector alone.");

// Methods
// cls_DsgPrs_EqualDistancePresentation.def_static("operator new_", (void * (*)(size_t)) &DsgPrs_EqualDistancePresentation::operator new, "None", py::arg("theSize"));
// cls_DsgPrs_EqualDistancePresentation.def_static("operator delete_", (void (*)(void *)) &DsgPrs_EqualDistancePresentation::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs_EqualDistancePresentation.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs_EqualDistancePresentation::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs_EqualDistancePresentation.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs_EqualDistancePresentation::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs_EqualDistancePresentation.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs_EqualDistancePresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs_EqualDistancePresentation.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs_EqualDistancePresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs_EqualDistancePresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const opencascade::handle<Geom_Plane> &)) &DsgPrs_EqualDistancePresentation::Add, "Adds the points Point1, Point2, Point3 Point4, and the plane Plane to the presentation object aPresentation. The display attributes of these elements is defined by the attribute manager aDrawer. The distance is the length of a projection from the shape to the plane. These distances are used to compare two shapes by this vector alone.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("Point1"), py::arg("Point2"), py::arg("Point3"), py::arg("Point4"), py::arg("Plane"));
cls_DsgPrs_EqualDistancePresentation.def_static("AddInterval_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const gp_Pnt &, const gp_Pnt &, const gp_Dir &, const gp_Pnt &, const DsgPrs_ArrowSide, gp_Pnt &, gp_Pnt &)) &DsgPrs_EqualDistancePresentation::AddInterval, "is used for presentation of interval between two lines or two points or between a line and a point.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aPoint1"), py::arg("aPoint2"), py::arg("aDir"), py::arg("aPosition"), py::arg("anArrowSide"), py::arg("anExtremePnt1"), py::arg("anExtremePnt2"));
cls_DsgPrs_EqualDistancePresentation.def_static("AddIntervalBetweenTwoArcs_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const gp_Circ &, const gp_Circ &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const DsgPrs_ArrowSide)) &DsgPrs_EqualDistancePresentation::AddIntervalBetweenTwoArcs, "is used for presentation of interval between two arcs. One of arcs can have a zero radius.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aCircle1"), py::arg("aCircle2"), py::arg("aPoint1"), py::arg("aPoint2"), py::arg("aPoint3"), py::arg("aPoint4"), py::arg("anArrowSide"));

// CLASS: DSGPRS_EQUALRADIUSPRESENTATION
py::class_<DsgPrs_EqualRadiusPresentation> cls_DsgPrs_EqualRadiusPresentation(mod, "DsgPrs_EqualRadiusPresentation", "A framework to define display of equality in radii.");

// Methods
// cls_DsgPrs_EqualRadiusPresentation.def_static("operator new_", (void * (*)(size_t)) &DsgPrs_EqualRadiusPresentation::operator new, "None", py::arg("theSize"));
// cls_DsgPrs_EqualRadiusPresentation.def_static("operator delete_", (void (*)(void *)) &DsgPrs_EqualRadiusPresentation::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs_EqualRadiusPresentation.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs_EqualRadiusPresentation::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs_EqualRadiusPresentation.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs_EqualRadiusPresentation::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs_EqualRadiusPresentation.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs_EqualRadiusPresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs_EqualRadiusPresentation.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs_EqualRadiusPresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs_EqualRadiusPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const opencascade::handle<Geom_Plane> &)) &DsgPrs_EqualRadiusPresentation::Add, "Adds the points FirstCenter, SecondCenter, FirstPoint, SecondPoint, and the plane Plane to the presentation object aPresentation. The display attributes of these elements is defined by the attribute manager aDrawer. FirstCenter and SecondCenter are the centers of the first and second shapes respectively, and FirstPoint and SecondPoint are the attachment points of the radii to arcs.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("FirstCenter"), py::arg("SecondCenter"), py::arg("FirstPoint"), py::arg("SecondPoint"), py::arg("Plane"));

// CLASS: DSGPRS_FILLETRADIUSPRESENTATION
py::class_<DsgPrs_FilletRadiusPresentation> cls_DsgPrs_FilletRadiusPresentation(mod, "DsgPrs_FilletRadiusPresentation", "A framework for displaying radii of fillets.");

// Methods
// cls_DsgPrs_FilletRadiusPresentation.def_static("operator new_", (void * (*)(size_t)) &DsgPrs_FilletRadiusPresentation::operator new, "None", py::arg("theSize"));
// cls_DsgPrs_FilletRadiusPresentation.def_static("operator delete_", (void (*)(void *)) &DsgPrs_FilletRadiusPresentation::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs_FilletRadiusPresentation.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs_FilletRadiusPresentation::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs_FilletRadiusPresentation.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs_FilletRadiusPresentation::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs_FilletRadiusPresentation.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs_FilletRadiusPresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs_FilletRadiusPresentation.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs_FilletRadiusPresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs_FilletRadiusPresentation.def_static("Add_", [](const opencascade::handle<Prs3d_Presentation> & aPresentation, const opencascade::handle<Prs3d_Drawer> & aDrawer, const Standard_Real thevalue, const TCollection_ExtendedString & aText, const gp_Pnt & aPosition, const gp_Dir & aNormalDir, const gp_Pnt & aBasePnt, const gp_Pnt & aFirstPoint, const gp_Pnt & aSecondPoint, const gp_Pnt & aCenter, const DsgPrs_ArrowSide ArrowPrs, const Standard_Boolean drawRevers, gp_Pnt & DrawPosition, gp_Pnt & EndOfArrow, opencascade::handle<Geom_TrimmedCurve> & TrimCurve, Standard_Boolean & HasCircle){ DsgPrs_FilletRadiusPresentation::Add(aPresentation, aDrawer, thevalue, aText, aPosition, aNormalDir, aBasePnt, aFirstPoint, aSecondPoint, aCenter, ArrowPrs, drawRevers, DrawPosition, EndOfArrow, TrimCurve, HasCircle); return HasCircle; }, "Adds a display of the radius of a fillet to the presentation aPresentation. The display ttributes defined by the attribute manager aDrawer. the value specifies the length of the radius.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("thevalue"), py::arg("aText"), py::arg("aPosition"), py::arg("aNormalDir"), py::arg("aBasePnt"), py::arg("aFirstPoint"), py::arg("aSecondPoint"), py::arg("aCenter"), py::arg("ArrowPrs"), py::arg("drawRevers"), py::arg("DrawPosition"), py::arg("EndOfArrow"), py::arg("TrimCurve"), py::arg("HasCircle"));

// CLASS: DSGPRS_FIXPRESENTATION
py::class_<DsgPrs_FixPresentation> cls_DsgPrs_FixPresentation(mod, "DsgPrs_FixPresentation", "class which draws the presentation of Fixed objects");

// Methods
// cls_DsgPrs_FixPresentation.def_static("operator new_", (void * (*)(size_t)) &DsgPrs_FixPresentation::operator new, "None", py::arg("theSize"));
// cls_DsgPrs_FixPresentation.def_static("operator delete_", (void (*)(void *)) &DsgPrs_FixPresentation::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs_FixPresentation.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs_FixPresentation::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs_FixPresentation.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs_FixPresentation::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs_FixPresentation.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs_FixPresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs_FixPresentation.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs_FixPresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs_FixPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const gp_Pnt &, const gp_Pnt &, const gp_Dir &, const Standard_Real)) &DsgPrs_FixPresentation::Add, "draws the presentation of fixed objects by drawing the 'fix' symbol at position <aPntEnd>. A binding segment is drawn between <aPntAttach> ( which belongs the the fix object) and <aPntEnd>. aSymbSize is the size of the 'fix'symbol", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aPntAttach"), py::arg("aPntEnd"), py::arg("aNormPln"), py::arg("aSymbSize"));

// CLASS: DSGPRS_IDENTICPRESENTATION
py::class_<DsgPrs_IdenticPresentation> cls_DsgPrs_IdenticPresentation(mod, "DsgPrs_IdenticPresentation", "None");

// Methods
// cls_DsgPrs_IdenticPresentation.def_static("operator new_", (void * (*)(size_t)) &DsgPrs_IdenticPresentation::operator new, "None", py::arg("theSize"));
// cls_DsgPrs_IdenticPresentation.def_static("operator delete_", (void (*)(void *)) &DsgPrs_IdenticPresentation::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs_IdenticPresentation.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs_IdenticPresentation::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs_IdenticPresentation.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs_IdenticPresentation::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs_IdenticPresentation.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs_IdenticPresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs_IdenticPresentation.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs_IdenticPresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs_IdenticPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TCollection_ExtendedString &, const gp_Pnt &, const gp_Pnt &)) &DsgPrs_IdenticPresentation::Add, "draws a line between <aPntAttach> and <aPntOffset>.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aText"), py::arg("aPntAttach"), py::arg("aPntOffset"));
cls_DsgPrs_IdenticPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TCollection_ExtendedString &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &)) &DsgPrs_IdenticPresentation::Add, "draws the 'identic' presentation by drawing a line between <aFAttach> and <aSAttach> , and a linkimg segment between <aPntOffset> and its projection on the precedent line.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aText"), py::arg("aFAttach"), py::arg("aSAttach"), py::arg("aPntOffset"));
cls_DsgPrs_IdenticPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TCollection_ExtendedString &, const gp_Ax2 &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &)) &DsgPrs_IdenticPresentation::Add, "draws the 'identic' presentation in the case of circles : draws an arc of circle between <aFAttach> and <aSAttach> of center <aCenter> and of radius dist(aCenter, aFAttach), and draws a segment between <aPntOffset> and its projection on the arc.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aText"), py::arg("aAx2"), py::arg("aCenter"), py::arg("aFAttach"), py::arg("aSAttach"), py::arg("aPntOffset"));
cls_DsgPrs_IdenticPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TCollection_ExtendedString &, const gp_Ax2 &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &)) &DsgPrs_IdenticPresentation::Add, "draws the 'identic' presentation in the case of circles : draws an arc of circle between <aFAttach> and <aSAttach> of center <aCenter> and of radius dist(aCenter, aFAttach), and draws a segment between <aPntOffset> and <aPntOnCirc>", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aText"), py::arg("aAx2"), py::arg("aCenter"), py::arg("aFAttach"), py::arg("aSAttach"), py::arg("aPntOffset"), py::arg("aPntOnCirc"));
cls_DsgPrs_IdenticPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TCollection_ExtendedString &, const gp_Elips &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &)) &DsgPrs_IdenticPresentation::Add, "draws the 'identic' presentation in the case of ellipses: draws an arc of the anEllipse between <aFAttach> and <aSAttach> and draws a segment between <aPntOffset> and <aPntOnElli>", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aText"), py::arg("anEllipse"), py::arg("aFAttach"), py::arg("aSAttach"), py::arg("aPntOffset"), py::arg("aPntOnElli"));

// CLASS: DSGPRS_LENGTHPRESENTATION
py::class_<DsgPrs_LengthPresentation> cls_DsgPrs_LengthPresentation(mod, "DsgPrs_LengthPresentation", "Framework for displaying lengths. The length displayed is indicated by line segments and text alone or by a combination of line segment, text and arrows at either or both of its ends.");

// Methods
// cls_DsgPrs_LengthPresentation.def_static("operator new_", (void * (*)(size_t)) &DsgPrs_LengthPresentation::operator new, "None", py::arg("theSize"));
// cls_DsgPrs_LengthPresentation.def_static("operator delete_", (void (*)(void *)) &DsgPrs_LengthPresentation::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs_LengthPresentation.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs_LengthPresentation::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs_LengthPresentation.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs_LengthPresentation::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs_LengthPresentation.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs_LengthPresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs_LengthPresentation.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs_LengthPresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs_LengthPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TCollection_ExtendedString &, const gp_Pnt &, const gp_Pnt &, const gp_Dir &, const gp_Pnt &)) &DsgPrs_LengthPresentation::Add, "Draws a line segment representing a length in the display aPresentation. This segment joins the points AttachmentPoint1 and AttachmentPoint2, along the direction aDirection. The text aText will be displayed at the offset point OffsetPoint. The line and text attributes are specified by the attribute manager aDrawer.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aText"), py::arg("AttachmentPoint1"), py::arg("AttachmentPoint2"), py::arg("aDirection"), py::arg("OffsetPoint"));
cls_DsgPrs_LengthPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TCollection_ExtendedString &, const gp_Pnt &, const gp_Pnt &, const gp_Dir &, const gp_Pnt &, const DsgPrs_ArrowSide)) &DsgPrs_LengthPresentation::Add, "Draws a line segment representing a length in the display aPresentation. This segment joins the points AttachmentPoint1 and AttachmentPoint2, along the direction aDirection. The text aText will be displayed at the offset point OffsetPoint. The value of the enumeration ArrowSide controls whether arrows will be displayed at either or both ends of the length. The line, text and arrow attributes are specified by the attribute manager aDrawer.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aText"), py::arg("AttachmentPoint1"), py::arg("AttachmentPoint2"), py::arg("aDirection"), py::arg("OffsetPoint"), py::arg("ArrowSide"));
cls_DsgPrs_LengthPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TCollection_ExtendedString &, const gp_Pnt &, const gp_Pnt &, const gp_Pln &, const gp_Dir &, const gp_Pnt &, const DsgPrs_ArrowSide)) &DsgPrs_LengthPresentation::Add, "Draws a line segment representing a length in the display aPresentation. This segment joins the points AttachmentPoint1 and AttachmentPoint2, along the direction aDirection. The text aText will be displayed at the offset point OffsetPoint. The value of the enumeration ArrowSide controls whether arrows will be displayed at either or both ends of the length. The plane PlaneOfFaces is used if length is null. The line, text and arrow attributes are specified by the attribute manager aDrawer.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aText"), py::arg("AttachmentPoint1"), py::arg("AttachmentPoint2"), py::arg("PlaneOfFaces"), py::arg("aDirection"), py::arg("OffsetPoint"), py::arg("ArrowSide"));
cls_DsgPrs_LengthPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TCollection_ExtendedString &, const opencascade::handle<Geom_Surface> &, const gp_Pnt &, const gp_Pnt &, const gp_Dir &, const gp_Pnt &, const DsgPrs_ArrowSide)) &DsgPrs_LengthPresentation::Add, "Draws a line segment representing a length in the display aPresentation. This segment joins the points AttachmentPoint1 and AttachmentPoint2, along the direction aDirection. AttachmentPoint2 lies on the curvilinear faces SecondSurf. The text aText will be displayed at the offset point OffsetPoint. The value of the enumeration ArrowSide controls whether arrows will be displayed at either or both ends of the length. The line, text and arrow attributes are specified by the attribute manager aDrawer.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aText"), py::arg("SecondSurf"), py::arg("AttachmentPoint1"), py::arg("AttachmentPoint2"), py::arg("aDirection"), py::arg("OffsetPoint"), py::arg("ArrowSide"));
cls_DsgPrs_LengthPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const gp_Pnt &, const gp_Pnt &, const DsgPrs_ArrowSide)) &DsgPrs_LengthPresentation::Add, "Draws a line segment representing a length in the display aPresentation. This segment joins the points AttachmentPoint1 and AttachmentPoint2, along the direction aDirection. The value of the enumeration ArrowSide controls whether arrows will be displayed at either or both ends of the length. The line and arrow attributes are specified by the attribute manager aDrawer.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("Pt1"), py::arg("Pt2"), py::arg("ArrowSide"));

// CLASS: DSGPRS_MIDPOINTPRESENTATION
py::class_<DsgPrs_MidPointPresentation> cls_DsgPrs_MidPointPresentation(mod, "DsgPrs_MidPointPresentation", "None");

// Methods
// cls_DsgPrs_MidPointPresentation.def_static("operator new_", (void * (*)(size_t)) &DsgPrs_MidPointPresentation::operator new, "None", py::arg("theSize"));
// cls_DsgPrs_MidPointPresentation.def_static("operator delete_", (void (*)(void *)) &DsgPrs_MidPointPresentation::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs_MidPointPresentation.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs_MidPointPresentation::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs_MidPointPresentation.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs_MidPointPresentation::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs_MidPointPresentation.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs_MidPointPresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs_MidPointPresentation.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs_MidPointPresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs_MidPointPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const gp_Ax2 &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const Standard_Boolean)) &DsgPrs_MidPointPresentation::Add, "draws the representation of a MidPoint between two vertices.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("theAxe"), py::arg("MidPoint"), py::arg("Position"), py::arg("AttachPoint"), py::arg("first"));
cls_DsgPrs_MidPointPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const gp_Ax2 &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const Standard_Boolean)) &DsgPrs_MidPointPresentation::Add, "draws the representation of a MidPoint between two lines or linear segments.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("theAxe"), py::arg("MidPoint"), py::arg("Position"), py::arg("AttachPoint"), py::arg("Point1"), py::arg("Point2"), py::arg("first"));
cls_DsgPrs_MidPointPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const gp_Circ &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const Standard_Boolean)) &DsgPrs_MidPointPresentation::Add, "draws the representation of a MidPoint between two entire circles or two circular arcs.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aCircle"), py::arg("MidPoint"), py::arg("Position"), py::arg("AttachPoint"), py::arg("Point1"), py::arg("Point2"), py::arg("first"));
cls_DsgPrs_MidPointPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const gp_Elips &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const Standard_Boolean)) &DsgPrs_MidPointPresentation::Add, "draws the representation of a MidPoint between two entire ellipses or two elliptic arcs.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("anElips"), py::arg("MidPoint"), py::arg("Position"), py::arg("AttachPoint"), py::arg("Point1"), py::arg("Point2"), py::arg("first"));

// CLASS: DSGPRS_OFFSETPRESENTATION
py::class_<DsgPrs_OffsetPresentation> cls_DsgPrs_OffsetPresentation(mod, "DsgPrs_OffsetPresentation", "A framework to define display of offsets.");

// Methods
// cls_DsgPrs_OffsetPresentation.def_static("operator new_", (void * (*)(size_t)) &DsgPrs_OffsetPresentation::operator new, "None", py::arg("theSize"));
// cls_DsgPrs_OffsetPresentation.def_static("operator delete_", (void (*)(void *)) &DsgPrs_OffsetPresentation::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs_OffsetPresentation.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs_OffsetPresentation::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs_OffsetPresentation.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs_OffsetPresentation::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs_OffsetPresentation.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs_OffsetPresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs_OffsetPresentation.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs_OffsetPresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs_OffsetPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TCollection_ExtendedString &, const gp_Pnt &, const gp_Pnt &, const gp_Dir &, const gp_Dir &, const gp_Pnt &)) &DsgPrs_OffsetPresentation::Add, "Defines the display of elements showing offset shapes. These include the two points of attachment AttachmentPoint1 and AttachmentPoint1, the two directions aDirection and aDirection2, and the offset point OffsetPoint. These arguments are added to the presentation object aPresentation. Their display attributes are defined by the attribute manager aDrawer.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aText"), py::arg("AttachmentPoint1"), py::arg("AttachmentPoint2"), py::arg("aDirection"), py::arg("aDirection2"), py::arg("OffsetPoint"));
cls_DsgPrs_OffsetPresentation.def_static("AddAxes_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TCollection_ExtendedString &, const gp_Pnt &, const gp_Pnt &, const gp_Dir &, const gp_Dir &, const gp_Pnt &)) &DsgPrs_OffsetPresentation::AddAxes, "draws the representation of axes alignement Constraint between the point AttachmentPoint1 and the point AttachmentPoint2, along direction aDirection, using the offset point OffsetPoint.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aText"), py::arg("AttachmentPoint1"), py::arg("AttachmentPoint2"), py::arg("aDirection"), py::arg("aDirection2"), py::arg("OffsetPoint"));

// CLASS: DSGPRS_PARALPRESENTATION
py::class_<DsgPrs_ParalPresentation> cls_DsgPrs_ParalPresentation(mod, "DsgPrs_ParalPresentation", "A framework to define display of relations of parallelism between shapes.");

// Methods
// cls_DsgPrs_ParalPresentation.def_static("operator new_", (void * (*)(size_t)) &DsgPrs_ParalPresentation::operator new, "None", py::arg("theSize"));
// cls_DsgPrs_ParalPresentation.def_static("operator delete_", (void (*)(void *)) &DsgPrs_ParalPresentation::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs_ParalPresentation.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs_ParalPresentation::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs_ParalPresentation.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs_ParalPresentation::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs_ParalPresentation.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs_ParalPresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs_ParalPresentation.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs_ParalPresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs_ParalPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TCollection_ExtendedString &, const gp_Pnt &, const gp_Pnt &, const gp_Dir &, const gp_Pnt &)) &DsgPrs_ParalPresentation::Add, "Defines the display of elements showing relations of parallelism between shapes. These include the two points of attachment AttachmentPoint1 and AttachmentPoint1, the direction aDirection, and the offset point OffsetPoint. These arguments are added to the presentation object aPresentation. Their display attributes are defined by the attribute manager aDrawer.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aText"), py::arg("AttachmentPoint1"), py::arg("AttachmentPoint2"), py::arg("aDirection"), py::arg("OffsetPoint"));
cls_DsgPrs_ParalPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TCollection_ExtendedString &, const gp_Pnt &, const gp_Pnt &, const gp_Dir &, const gp_Pnt &, const DsgPrs_ArrowSide)) &DsgPrs_ParalPresentation::Add, "Defines the display of elements showing relations of parallelism between shapes. These include the two points of attachment AttachmentPoint1 and AttachmentPoint1, the direction aDirection, the offset point OffsetPoint and the text aText. These arguments are added to the presentation object aPresentation. Their display attributes are defined by the attribute manager aDrawer.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aText"), py::arg("AttachmentPoint1"), py::arg("AttachmentPoint2"), py::arg("aDirection"), py::arg("OffsetPoint"), py::arg("ArrowSide"));

// CLASS: DSGPRS_PERPENPRESENTATION
py::class_<DsgPrs_PerpenPresentation> cls_DsgPrs_PerpenPresentation(mod, "DsgPrs_PerpenPresentation", "A framework to define display of perpendicular constraints between shapes.");

// Methods
// cls_DsgPrs_PerpenPresentation.def_static("operator new_", (void * (*)(size_t)) &DsgPrs_PerpenPresentation::operator new, "None", py::arg("theSize"));
// cls_DsgPrs_PerpenPresentation.def_static("operator delete_", (void (*)(void *)) &DsgPrs_PerpenPresentation::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs_PerpenPresentation.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs_PerpenPresentation::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs_PerpenPresentation.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs_PerpenPresentation::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs_PerpenPresentation.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs_PerpenPresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs_PerpenPresentation.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs_PerpenPresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs_PerpenPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const Standard_Boolean, const Standard_Boolean)) &DsgPrs_PerpenPresentation::Add, "Defines the display of elements showing perpendicular constraints between shapes. These include the two axis points pAx1 and pAx2, the two points pnt1 and pnt2, the offset point OffsetPoint and the two Booleans intOut1} and intOut2{. These arguments are added to the presentation object aPresentation. Their display attributes are defined by the attribute manager aDrawer.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("pAx1"), py::arg("pAx2"), py::arg("pnt1"), py::arg("pnt2"), py::arg("OffsetPoint"), py::arg("intOut1"), py::arg("intOut2"));

// CLASS: DSGPRS_RADIUSPRESENTATION
py::class_<DsgPrs_RadiusPresentation> cls_DsgPrs_RadiusPresentation(mod, "DsgPrs_RadiusPresentation", "A framework to define display of radii.");

// Methods
// cls_DsgPrs_RadiusPresentation.def_static("operator new_", (void * (*)(size_t)) &DsgPrs_RadiusPresentation::operator new, "None", py::arg("theSize"));
// cls_DsgPrs_RadiusPresentation.def_static("operator delete_", (void (*)(void *)) &DsgPrs_RadiusPresentation::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs_RadiusPresentation.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs_RadiusPresentation::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs_RadiusPresentation.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs_RadiusPresentation::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs_RadiusPresentation.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs_RadiusPresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs_RadiusPresentation.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs_RadiusPresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs_RadiusPresentation.def_static("Add_", [](const opencascade::handle<Prs3d_Presentation> & a0, const opencascade::handle<Prs3d_Drawer> & a1, const TCollection_ExtendedString & a2, const gp_Pnt & a3, const gp_Circ & a4, const Standard_Real a5, const Standard_Real a6) -> void { return DsgPrs_RadiusPresentation::Add(a0, a1, a2, a3, a4, a5, a6); });
cls_DsgPrs_RadiusPresentation.def_static("Add_", [](const opencascade::handle<Prs3d_Presentation> & a0, const opencascade::handle<Prs3d_Drawer> & a1, const TCollection_ExtendedString & a2, const gp_Pnt & a3, const gp_Circ & a4, const Standard_Real a5, const Standard_Real a6, const Standard_Boolean a7) -> void { return DsgPrs_RadiusPresentation::Add(a0, a1, a2, a3, a4, a5, a6, a7); });
cls_DsgPrs_RadiusPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TCollection_ExtendedString &, const gp_Pnt &, const gp_Circ &, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean)) &DsgPrs_RadiusPresentation::Add, "Adds the point AttachmentPoint, the circle aCircle, the text aText, and the parameters firstparam and lastparam to the presentation object aPresentation. The display attributes of these elements is defined by the attribute manager aDrawer. If the Boolean drawFromCenter is false, the arrowhead will point towards the center of aCircle. If the Boolean reverseArrow is true, the arrowhead will point away from the attachment point.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aText"), py::arg("AttachmentPoint"), py::arg("aCircle"), py::arg("firstparam"), py::arg("lastparam"), py::arg("drawFromCenter"), py::arg("reverseArrow"));
// cls_DsgPrs_RadiusPresentation.def_static("Add_", [](const opencascade::handle<Prs3d_Presentation> & a0, const opencascade::handle<Prs3d_Drawer> & a1, const TCollection_ExtendedString & a2, const gp_Pnt & a3, const gp_Circ & a4, const Standard_Real a5, const Standard_Real a6, const DsgPrs_ArrowSide a7) -> void { return DsgPrs_RadiusPresentation::Add(a0, a1, a2, a3, a4, a5, a6, a7); });
// cls_DsgPrs_RadiusPresentation.def_static("Add_", [](const opencascade::handle<Prs3d_Presentation> & a0, const opencascade::handle<Prs3d_Drawer> & a1, const TCollection_ExtendedString & a2, const gp_Pnt & a3, const gp_Circ & a4, const Standard_Real a5, const Standard_Real a6, const DsgPrs_ArrowSide a7, const Standard_Boolean a8) -> void { return DsgPrs_RadiusPresentation::Add(a0, a1, a2, a3, a4, a5, a6, a7, a8); });
// cls_DsgPrs_RadiusPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TCollection_ExtendedString &, const gp_Pnt &, const gp_Circ &, const Standard_Real, const Standard_Real, const DsgPrs_ArrowSide, const Standard_Boolean, const Standard_Boolean)) &DsgPrs_RadiusPresentation::Add, "Adds the point AttachmentPoint, the circle aCircle, the text aText, and the parameters firstparam and lastparam to the presentation object aPresentation. The display attributes of these elements is defined by the attribute manager aDrawer. The value of the enumeration Arrowside determines the type of arrow displayed: whether there will be arrowheads at both ends or only one, for example. If the Boolean drawFromCenter is false, the arrowhead will point towards the center of aCircle. If the Boolean reverseArrow is true, the arrowhead will point away from the attachment point.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aText"), py::arg("AttachmentPoint"), py::arg("aCircle"), py::arg("firstparam"), py::arg("lastparam"), py::arg("ArrowSide"), py::arg("drawFromCenter"), py::arg("reverseArrow"));
cls_DsgPrs_RadiusPresentation.def_static("Add_", [](const opencascade::handle<Prs3d_Presentation> & a0, const opencascade::handle<Prs3d_Drawer> & a1, const TCollection_ExtendedString & a2, const gp_Pnt & a3, const gp_Pnt & a4, const gp_Pnt & a5, const DsgPrs_ArrowSide a6) -> void { return DsgPrs_RadiusPresentation::Add(a0, a1, a2, a3, a4, a5, a6); });
cls_DsgPrs_RadiusPresentation.def_static("Add_", [](const opencascade::handle<Prs3d_Presentation> & a0, const opencascade::handle<Prs3d_Drawer> & a1, const TCollection_ExtendedString & a2, const gp_Pnt & a3, const gp_Pnt & a4, const gp_Pnt & a5, const DsgPrs_ArrowSide a6, const Standard_Boolean a7) -> void { return DsgPrs_RadiusPresentation::Add(a0, a1, a2, a3, a4, a5, a6, a7); });
cls_DsgPrs_RadiusPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TCollection_ExtendedString &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const DsgPrs_ArrowSide, const Standard_Boolean, const Standard_Boolean)) &DsgPrs_RadiusPresentation::Add, "Adds the circle aCircle, the text aText, the points AttachmentPoint, Center and EndOfArrow to the presentation object aPresentation. The display attributes of these elements is defined by the attribute manager aDrawer. The value of the enumeration Arrowside determines the type of arrow displayed: whether there will be arrowheads at both ends or only one, for example. If the Boolean drawFromCenter is false, the arrowhead will point towards the center of aCircle. If the Boolean reverseArrow is true, the arrowhead will point away from the attachment point.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aText"), py::arg("AttachmentPoint"), py::arg("Center"), py::arg("EndOfArrow"), py::arg("ArrowSide"), py::arg("drawFromCenter"), py::arg("reverseArrow"));

// CLASS: DSGPRS_SHADEDPLANEPRESENTATION
py::class_<DsgPrs_ShadedPlanePresentation> cls_DsgPrs_ShadedPlanePresentation(mod, "DsgPrs_ShadedPlanePresentation", "A framework to define display of shaded planes.");

// Methods
// cls_DsgPrs_ShadedPlanePresentation.def_static("operator new_", (void * (*)(size_t)) &DsgPrs_ShadedPlanePresentation::operator new, "None", py::arg("theSize"));
// cls_DsgPrs_ShadedPlanePresentation.def_static("operator delete_", (void (*)(void *)) &DsgPrs_ShadedPlanePresentation::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs_ShadedPlanePresentation.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs_ShadedPlanePresentation::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs_ShadedPlanePresentation.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs_ShadedPlanePresentation::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs_ShadedPlanePresentation.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs_ShadedPlanePresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs_ShadedPlanePresentation.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs_ShadedPlanePresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs_ShadedPlanePresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &)) &DsgPrs_ShadedPlanePresentation::Add, "Adds the points aPt1, aPt2 and aPt3 to the presentation object, aPresentation. The display attributes of the shaded plane are defined by the attribute manager aDrawer.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aPt1"), py::arg("aPt2"), py::arg("aPt3"));

// CLASS: DSGPRS_SHAPEDIRPRESENTATION
py::class_<DsgPrs_ShapeDirPresentation> cls_DsgPrs_ShapeDirPresentation(mod, "DsgPrs_ShapeDirPresentation", "A framework to define display of the normal to the surface of a shape.");

// Methods
// cls_DsgPrs_ShapeDirPresentation.def_static("operator new_", (void * (*)(size_t)) &DsgPrs_ShapeDirPresentation::operator new, "None", py::arg("theSize"));
// cls_DsgPrs_ShapeDirPresentation.def_static("operator delete_", (void (*)(void *)) &DsgPrs_ShapeDirPresentation::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs_ShapeDirPresentation.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs_ShapeDirPresentation::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs_ShapeDirPresentation.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs_ShapeDirPresentation::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs_ShapeDirPresentation.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs_ShapeDirPresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs_ShapeDirPresentation.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs_ShapeDirPresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs_ShapeDirPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TopoDS_Shape &, const Standard_Integer)) &DsgPrs_ShapeDirPresentation::Add, "Adds the shape shape and the mode mode to the presentation object prs. The display attributes of the normal are defined by the attribute manager aDrawer. mode determines whether the first or the last point of the normal is given to the presentation object. If the first point: 0; if the last point, 1.", py::arg("prs"), py::arg("aDrawer"), py::arg("shape"), py::arg("mode"));

// CLASS: DSGPRS_SYMBPRESENTATION
py::class_<DsgPrs_SymbPresentation> cls_DsgPrs_SymbPresentation(mod, "DsgPrs_SymbPresentation", "A framework to define display of symbols.");

// Methods
// cls_DsgPrs_SymbPresentation.def_static("operator new_", (void * (*)(size_t)) &DsgPrs_SymbPresentation::operator new, "None", py::arg("theSize"));
// cls_DsgPrs_SymbPresentation.def_static("operator delete_", (void (*)(void *)) &DsgPrs_SymbPresentation::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs_SymbPresentation.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs_SymbPresentation::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs_SymbPresentation.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs_SymbPresentation::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs_SymbPresentation.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs_SymbPresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs_SymbPresentation.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs_SymbPresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs_SymbPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TCollection_ExtendedString &, const gp_Pnt &)) &DsgPrs_SymbPresentation::Add, "Adds the text aText and the point OffsetPoint to the presentation object aPresentation. The display attributes of the shaded plane are defined by the attribute manager aDrawer.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aText"), py::arg("OffsetPoint"));

// CLASS: DSGPRS_SYMMETRICPRESENTATION
py::class_<DsgPrs_SymmetricPresentation> cls_DsgPrs_SymmetricPresentation(mod, "DsgPrs_SymmetricPresentation", "A framework to define display of symmetry between shapes.");

// Methods
// cls_DsgPrs_SymmetricPresentation.def_static("operator new_", (void * (*)(size_t)) &DsgPrs_SymmetricPresentation::operator new, "None", py::arg("theSize"));
// cls_DsgPrs_SymmetricPresentation.def_static("operator delete_", (void (*)(void *)) &DsgPrs_SymmetricPresentation::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs_SymmetricPresentation.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs_SymmetricPresentation::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs_SymmetricPresentation.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs_SymmetricPresentation::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs_SymmetricPresentation.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs_SymmetricPresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs_SymmetricPresentation.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs_SymmetricPresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs_SymmetricPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const gp_Pnt &, const gp_Pnt &, const gp_Dir &, const gp_Lin &, const gp_Pnt &)) &DsgPrs_SymmetricPresentation::Add, "Adds the points OffsetPoint, AttachmentPoint1, AttachmentPoint2, the direction aDirection1 and the axis anAxis to the presentation object aPresentation. The display attributes of the symmetry are defined by the attribute manager aDrawer. This syntax is used for display of symmetries between two segments.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("AttachmentPoint1"), py::arg("AttachmentPoint2"), py::arg("aDirection1"), py::arg("aAxis"), py::arg("OffsetPoint"));
cls_DsgPrs_SymmetricPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const gp_Pnt &, const gp_Pnt &, const gp_Circ &, const gp_Lin &, const gp_Pnt &)) &DsgPrs_SymmetricPresentation::Add, "Adds the points OffsetPoint, AttachmentPoint1, AttachmentPoint2, the direction aDirection1 the circle aCircle1 and the axis anAxis to the presentation object aPresentation. The display attributes of the symmetry are defined by the attribute manager aDrawer. This syntax is used for display of symmetries between two arcs.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("AttachmentPoint1"), py::arg("AttachmentPoint2"), py::arg("aCircle1"), py::arg("aAxis"), py::arg("OffsetPoint"));
cls_DsgPrs_SymmetricPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const gp_Pnt &, const gp_Pnt &, const gp_Lin &, const gp_Pnt &)) &DsgPrs_SymmetricPresentation::Add, "Adds the points OffsetPoint, AttachmentPoint1, AttachmentPoint2 and the axis anAxis to the presentation object aPresentation. The display attributes of the symmetry are defined by the attribute manager aDrawer. This syntax is used for display of symmetries between two vertices.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("AttachmentPoint1"), py::arg("AttachmentPoint2"), py::arg("aAxis"), py::arg("OffsetPoint"));

// CLASS: DSGPRS_TANGENTPRESENTATION
py::class_<DsgPrs_TangentPresentation> cls_DsgPrs_TangentPresentation(mod, "DsgPrs_TangentPresentation", "A framework to define display of tangents.");

// Methods
// cls_DsgPrs_TangentPresentation.def_static("operator new_", (void * (*)(size_t)) &DsgPrs_TangentPresentation::operator new, "None", py::arg("theSize"));
// cls_DsgPrs_TangentPresentation.def_static("operator delete_", (void (*)(void *)) &DsgPrs_TangentPresentation::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs_TangentPresentation.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs_TangentPresentation::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs_TangentPresentation.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs_TangentPresentation::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs_TangentPresentation.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs_TangentPresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs_TangentPresentation.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs_TangentPresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs_TangentPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const gp_Pnt &, const gp_Dir &, const Standard_Real)) &DsgPrs_TangentPresentation::Add, "Adds the point OffsetPoint, the direction aDirection and the length aLength to the presentation object aPresentation. The display attributes of the tangent are defined by the attribute manager aDrawer.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("OffsetPoint"), py::arg("aDirection"), py::arg("aLength"));

// CLASS: DSGPRS_XYZAXISPRESENTATION
py::class_<DsgPrs_XYZAxisPresentation> cls_DsgPrs_XYZAxisPresentation(mod, "DsgPrs_XYZAxisPresentation", "A framework for displaying the axes of an XYZ trihedron.");

// Methods
// cls_DsgPrs_XYZAxisPresentation.def_static("operator new_", (void * (*)(size_t)) &DsgPrs_XYZAxisPresentation::operator new, "None", py::arg("theSize"));
// cls_DsgPrs_XYZAxisPresentation.def_static("operator delete_", (void (*)(void *)) &DsgPrs_XYZAxisPresentation::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs_XYZAxisPresentation.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs_XYZAxisPresentation::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs_XYZAxisPresentation.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs_XYZAxisPresentation::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs_XYZAxisPresentation.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs_XYZAxisPresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs_XYZAxisPresentation.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs_XYZAxisPresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs_XYZAxisPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_LineAspect> &, const gp_Dir &, const Standard_Real, const Standard_CString, const gp_Pnt &, const gp_Pnt &)) &DsgPrs_XYZAxisPresentation::Add, "Draws each axis of a trihedron displayed in the presentation aPresentation and with lines shown by the values of aLineAspect. Each axis is defined by: - the first and last points aPfirst and aPlast - the direction aDir and - the value aVal which provides a value for length. The value for length is provided so that the trihedron can vary in length relative to the scale of shape display. Each axis will be identified as X, Y, or Z by the text aText.", py::arg("aPresentation"), py::arg("anLineAspect"), py::arg("aDir"), py::arg("aVal"), py::arg("aText"), py::arg("aPfirst"), py::arg("aPlast"));
cls_DsgPrs_XYZAxisPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_LineAspect> &, const opencascade::handle<Prs3d_ArrowAspect> &, const opencascade::handle<Prs3d_TextAspect> &, const gp_Dir &, const Standard_Real, const Standard_CString, const gp_Pnt &, const gp_Pnt &)) &DsgPrs_XYZAxisPresentation::Add, "draws the presentation X ,Y ,Z axis", py::arg("aPresentation"), py::arg("aLineAspect"), py::arg("anArrowAspect"), py::arg("aTextAspect"), py::arg("aDir"), py::arg("aVal"), py::arg("aText"), py::arg("aPfirst"), py::arg("aPlast"));

// CLASS: DSGPRS_XYZPLANEPRESENTATION
py::class_<DsgPrs_XYZPlanePresentation> cls_DsgPrs_XYZPlanePresentation(mod, "DsgPrs_XYZPlanePresentation", "A framework for displaying the planes of an XYZ trihedron.");

// Methods
// cls_DsgPrs_XYZPlanePresentation.def_static("operator new_", (void * (*)(size_t)) &DsgPrs_XYZPlanePresentation::operator new, "None", py::arg("theSize"));
// cls_DsgPrs_XYZPlanePresentation.def_static("operator delete_", (void (*)(void *)) &DsgPrs_XYZPlanePresentation::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs_XYZPlanePresentation.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs_XYZPlanePresentation::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs_XYZPlanePresentation.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs_XYZPlanePresentation::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs_XYZPlanePresentation.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs_XYZPlanePresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs_XYZPlanePresentation.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs_XYZPlanePresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs_XYZPlanePresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &)) &DsgPrs_XYZPlanePresentation::Add, "Draws each plane of a trihedron displayed in the presentation aPresentation and with attributes defined by the attribute manager aDrawer. Each triangular plane is defined by the points aPt1 aPt2 and aPt3.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aPt1"), py::arg("aPt2"), py::arg("aPt3"));


}
