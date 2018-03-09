/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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
#include <pyOCCT_Common.hpp>

#include <FilletSurf_StatusType.hxx>
#include <ChFi3d_FilBuilder.hxx>
#include <TopoDS_Shape.hxx>
#include <ChFi3d_FilletShape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_ListOfShape.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <TopoDS_Face.hxx>
#include <Geom_Curve.hxx>
#include <Geom2d_Curve.hxx>
#include <Geom_TrimmedCurve.hxx>
#include <FilletSurf_InternalBuilder.hxx>
#include <FilletSurf_StatusDone.hxx>
#include <FilletSurf_ErrorTypeStatus.hxx>
#include <FilletSurf_Builder.hxx>

PYBIND11_MODULE(FilletSurf, mod) {

	// IMPORT
	py::module::import("OCCT.ChFi3d");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TopTools");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.Geom2d");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\FilletSurf_StatusType.hxx
	py::enum_<FilletSurf_StatusType>(mod, "FilletSurf_StatusType", "None")
		.value("FilletSurf_TwoExtremityOnEdge", FilletSurf_StatusType::FilletSurf_TwoExtremityOnEdge)
		.value("FilletSurf_OneExtremityOnEdge", FilletSurf_StatusType::FilletSurf_OneExtremityOnEdge)
		.value("FilletSurf_NoExtremityOnEdge", FilletSurf_StatusType::FilletSurf_NoExtremityOnEdge)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\FilletSurf_StatusDone.hxx
	py::enum_<FilletSurf_StatusDone>(mod, "FilletSurf_StatusDone", "None")
		.value("FilletSurf_IsOk", FilletSurf_StatusDone::FilletSurf_IsOk)
		.value("FilletSurf_IsNotOk", FilletSurf_StatusDone::FilletSurf_IsNotOk)
		.value("FilletSurf_IsPartial", FilletSurf_StatusDone::FilletSurf_IsPartial)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\FilletSurf_ErrorTypeStatus.hxx
	py::enum_<FilletSurf_ErrorTypeStatus>(mod, "FilletSurf_ErrorTypeStatus", "None")
		.value("FilletSurf_EmptyList", FilletSurf_ErrorTypeStatus::FilletSurf_EmptyList)
		.value("FilletSurf_EdgeNotG1", FilletSurf_ErrorTypeStatus::FilletSurf_EdgeNotG1)
		.value("FilletSurf_FacesNotG1", FilletSurf_ErrorTypeStatus::FilletSurf_FacesNotG1)
		.value("FilletSurf_EdgeNotOnShape", FilletSurf_ErrorTypeStatus::FilletSurf_EdgeNotOnShape)
		.value("FilletSurf_NotSharpEdge", FilletSurf_ErrorTypeStatus::FilletSurf_NotSharpEdge)
		.value("FilletSurf_PbFilletCompute", FilletSurf_ErrorTypeStatus::FilletSurf_PbFilletCompute)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\FilletSurf_InternalBuilder.hxx
	py::class_<FilletSurf_InternalBuilder, std::unique_ptr<FilletSurf_InternalBuilder, Deleter<FilletSurf_InternalBuilder>>, ChFi3d_FilBuilder> cls_FilletSurf_InternalBuilder(mod, "FilletSurf_InternalBuilder", "This class is private. It is used by the class Builder from FilletSurf. It computes geometric information about fillets.");
	cls_FilletSurf_InternalBuilder.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
	cls_FilletSurf_InternalBuilder.def(py::init<const TopoDS_Shape &, const ChFi3d_FilletShape>(), py::arg("S"), py::arg("FShape"));
	cls_FilletSurf_InternalBuilder.def(py::init<const TopoDS_Shape &, const ChFi3d_FilletShape, const Standard_Real>(), py::arg("S"), py::arg("FShape"), py::arg("Ta"));
	cls_FilletSurf_InternalBuilder.def(py::init<const TopoDS_Shape &, const ChFi3d_FilletShape, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("FShape"), py::arg("Ta"), py::arg("Tapp3d"));
	cls_FilletSurf_InternalBuilder.def(py::init<const TopoDS_Shape &, const ChFi3d_FilletShape, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("FShape"), py::arg("Ta"), py::arg("Tapp3d"), py::arg("Tapp2d"));
	cls_FilletSurf_InternalBuilder.def("Add", (Standard_Integer (FilletSurf_InternalBuilder::*)(const TopTools_ListOfShape &, const Standard_Real)) &FilletSurf_InternalBuilder::Add, "Initializes the contour with a list of Edges 0 : no problem 1 : empty list 2 : the edges are not G1 3 : two connected faces on a same support are not G1 4 : the edge is not on shape 5 : NotSharpEdge: the edge is not sharp", py::arg("E"), py::arg("R"));
	cls_FilletSurf_InternalBuilder.def("Perform", (void (FilletSurf_InternalBuilder::*)()) &FilletSurf_InternalBuilder::Perform, "None");
	cls_FilletSurf_InternalBuilder.def("Done", (Standard_Boolean (FilletSurf_InternalBuilder::*)() const ) &FilletSurf_InternalBuilder::Done, "None");
	cls_FilletSurf_InternalBuilder.def("NbSurface", (Standard_Integer (FilletSurf_InternalBuilder::*)() const ) &FilletSurf_InternalBuilder::NbSurface, "gives the number of NUBS surfaces of the Fillet.");
	cls_FilletSurf_InternalBuilder.def("SurfaceFillet", (const opencascade::handle<Geom_Surface> & (FilletSurf_InternalBuilder::*)(const Standard_Integer) const ) &FilletSurf_InternalBuilder::SurfaceFillet, "gives the NUBS surface of index Index.", py::arg("Index"));
	cls_FilletSurf_InternalBuilder.def("TolApp3d", (Standard_Real (FilletSurf_InternalBuilder::*)(const Standard_Integer) const ) &FilletSurf_InternalBuilder::TolApp3d, "gives the 3d tolerance reached during approximation of the surface of index Index", py::arg("Index"));
	cls_FilletSurf_InternalBuilder.def("SupportFace1", (const TopoDS_Face & (FilletSurf_InternalBuilder::*)(const Standard_Integer) const ) &FilletSurf_InternalBuilder::SupportFace1, "gives the first support face relative to SurfaceFillet(Index);", py::arg("Index"));
	cls_FilletSurf_InternalBuilder.def("SupportFace2", (const TopoDS_Face & (FilletSurf_InternalBuilder::*)(const Standard_Integer) const ) &FilletSurf_InternalBuilder::SupportFace2, "gives the second support face relative to SurfaceFillet(Index);", py::arg("Index"));
	cls_FilletSurf_InternalBuilder.def("CurveOnFace1", (const opencascade::handle<Geom_Curve> & (FilletSurf_InternalBuilder::*)(const Standard_Integer) const ) &FilletSurf_InternalBuilder::CurveOnFace1, "gives the 3d curve of SurfaceFillet(Index) on SupportFace1(Index)", py::arg("Index"));
	cls_FilletSurf_InternalBuilder.def("CurveOnFace2", (const opencascade::handle<Geom_Curve> & (FilletSurf_InternalBuilder::*)(const Standard_Integer) const ) &FilletSurf_InternalBuilder::CurveOnFace2, "gives the 3d curve of SurfaceFillet(Index) on SupportFace2(Index)", py::arg("Index"));
	cls_FilletSurf_InternalBuilder.def("PCurveOnFace1", (const opencascade::handle<Geom2d_Curve> & (FilletSurf_InternalBuilder::*)(const Standard_Integer) const ) &FilletSurf_InternalBuilder::PCurveOnFace1, "gives the PCurve associated to CurvOnSup1(Index) on the support face", py::arg("Index"));
	cls_FilletSurf_InternalBuilder.def("PCurve1OnFillet", (const opencascade::handle<Geom2d_Curve> & (FilletSurf_InternalBuilder::*)(const Standard_Integer) const ) &FilletSurf_InternalBuilder::PCurve1OnFillet, "gives the PCurve associated to CurveOnFace1(Index) on the Fillet", py::arg("Index"));
	cls_FilletSurf_InternalBuilder.def("PCurveOnFace2", (const opencascade::handle<Geom2d_Curve> & (FilletSurf_InternalBuilder::*)(const Standard_Integer) const ) &FilletSurf_InternalBuilder::PCurveOnFace2, "gives the PCurve associated to CurveOnSup2(Index) on the support face", py::arg("Index"));
	cls_FilletSurf_InternalBuilder.def("PCurve2OnFillet", (const opencascade::handle<Geom2d_Curve> & (FilletSurf_InternalBuilder::*)(const Standard_Integer) const ) &FilletSurf_InternalBuilder::PCurve2OnFillet, "gives the PCurve associated to CurveOnSup2(Index) on the fillet", py::arg("Index"));
	cls_FilletSurf_InternalBuilder.def("FirstParameter", (Standard_Real (FilletSurf_InternalBuilder::*)() const ) &FilletSurf_InternalBuilder::FirstParameter, "gives the parameter of the fillet on the first edge.");
	cls_FilletSurf_InternalBuilder.def("LastParameter", (Standard_Real (FilletSurf_InternalBuilder::*)() const ) &FilletSurf_InternalBuilder::LastParameter, "gives the parameter of the fillet on the last edge");
	cls_FilletSurf_InternalBuilder.def("StartSectionStatus", (FilletSurf_StatusType (FilletSurf_InternalBuilder::*)() const ) &FilletSurf_InternalBuilder::StartSectionStatus, "None");
	cls_FilletSurf_InternalBuilder.def("EndSectionStatus", (FilletSurf_StatusType (FilletSurf_InternalBuilder::*)() const ) &FilletSurf_InternalBuilder::EndSectionStatus, "None");
	cls_FilletSurf_InternalBuilder.def("Simulate", (void (FilletSurf_InternalBuilder::*)()) &FilletSurf_InternalBuilder::Simulate, "None");
	cls_FilletSurf_InternalBuilder.def("NbSection", (Standard_Integer (FilletSurf_InternalBuilder::*)(const Standard_Integer) const ) &FilletSurf_InternalBuilder::NbSection, "None", py::arg("IndexSurf"));
	cls_FilletSurf_InternalBuilder.def("Section", (void (FilletSurf_InternalBuilder::*)(const Standard_Integer, const Standard_Integer, opencascade::handle<Geom_TrimmedCurve> &) const ) &FilletSurf_InternalBuilder::Section, "None", py::arg("IndexSurf"), py::arg("IndexSec"), py::arg("Circ"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\FilletSurf_Builder.hxx
	py::class_<FilletSurf_Builder, std::unique_ptr<FilletSurf_Builder, Deleter<FilletSurf_Builder>>> cls_FilletSurf_Builder(mod, "FilletSurf_Builder", "API giving the following geometric information about fillets list of corresponding NUBS surfaces for each surface: the 2 support faces on each face: the 3d curve and the corresponding 2d curve the 2d curves on the fillet status of start and end section of the fillet first and last parameter on edge of the fillet.");
	cls_FilletSurf_Builder.def(py::init<const TopoDS_Shape &, const TopTools_ListOfShape &, const Standard_Real>(), py::arg("S"), py::arg("E"), py::arg("R"));
	cls_FilletSurf_Builder.def(py::init<const TopoDS_Shape &, const TopTools_ListOfShape &, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("E"), py::arg("R"), py::arg("Ta"));
	cls_FilletSurf_Builder.def(py::init<const TopoDS_Shape &, const TopTools_ListOfShape &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("E"), py::arg("R"), py::arg("Ta"), py::arg("Tapp3d"));
	cls_FilletSurf_Builder.def(py::init<const TopoDS_Shape &, const TopTools_ListOfShape &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("E"), py::arg("R"), py::arg("Ta"), py::arg("Tapp3d"), py::arg("Tapp2d"));
	cls_FilletSurf_Builder.def("Perform", (void (FilletSurf_Builder::*)()) &FilletSurf_Builder::Perform, "---Purpose computation of the fillet (list of NUBS)");
	cls_FilletSurf_Builder.def("Simulate", (void (FilletSurf_Builder::*)()) &FilletSurf_Builder::Simulate, "None");
	cls_FilletSurf_Builder.def("IsDone", (FilletSurf_StatusDone (FilletSurf_Builder::*)() const ) &FilletSurf_Builder::IsDone, "gives the status about the computation of the fillet returns: IsOK :no problem during the computation IsNotOk: no result is produced IsPartial: the result is partial");
	cls_FilletSurf_Builder.def("StatusError", (FilletSurf_ErrorTypeStatus (FilletSurf_Builder::*)() const ) &FilletSurf_Builder::StatusError, "gives information about error status if IsDone=IsNotOk returns EdgeNotG1: the edges are not G1 FacesNotG1 : two connected faces on a same support are not G1 EdgeNotOnShape: the edge is not on shape NotSharpEdge: the edge is not sharp PbFilletCompute: problem during the computation of the fillet");
	cls_FilletSurf_Builder.def("NbSurface", (Standard_Integer (FilletSurf_Builder::*)() const ) &FilletSurf_Builder::NbSurface, "gives the number of NUBS surfaces of the Fillet.");
	cls_FilletSurf_Builder.def("SurfaceFillet", (const opencascade::handle<Geom_Surface> & (FilletSurf_Builder::*)(const Standard_Integer) const ) &FilletSurf_Builder::SurfaceFillet, "gives the NUBS surface of index Index.", py::arg("Index"));
	cls_FilletSurf_Builder.def("TolApp3d", (Standard_Real (FilletSurf_Builder::*)(const Standard_Integer) const ) &FilletSurf_Builder::TolApp3d, "gives the 3d tolerance reached during approximation of surface of index Index", py::arg("Index"));
	cls_FilletSurf_Builder.def("SupportFace1", (const TopoDS_Face & (FilletSurf_Builder::*)(const Standard_Integer) const ) &FilletSurf_Builder::SupportFace1, "gives the first support face relative to SurfaceFillet(Index);", py::arg("Index"));
	cls_FilletSurf_Builder.def("SupportFace2", (const TopoDS_Face & (FilletSurf_Builder::*)(const Standard_Integer) const ) &FilletSurf_Builder::SupportFace2, "gives the second support face relative to SurfaceFillet(Index);", py::arg("Index"));
	cls_FilletSurf_Builder.def("CurveOnFace1", (const opencascade::handle<Geom_Curve> & (FilletSurf_Builder::*)(const Standard_Integer) const ) &FilletSurf_Builder::CurveOnFace1, "gives the 3d curve of SurfaceFillet(Index) on SupportFace1(Index)", py::arg("Index"));
	cls_FilletSurf_Builder.def("CurveOnFace2", (const opencascade::handle<Geom_Curve> & (FilletSurf_Builder::*)(const Standard_Integer) const ) &FilletSurf_Builder::CurveOnFace2, "gives the 3d curve of SurfaceFillet(Index) on SupportFace2(Index)", py::arg("Index"));
	cls_FilletSurf_Builder.def("PCurveOnFace1", (const opencascade::handle<Geom2d_Curve> & (FilletSurf_Builder::*)(const Standard_Integer) const ) &FilletSurf_Builder::PCurveOnFace1, "gives the PCurve associated to CurvOnSup1(Index) on the support face", py::arg("Index"));
	cls_FilletSurf_Builder.def("PCurve1OnFillet", (const opencascade::handle<Geom2d_Curve> & (FilletSurf_Builder::*)(const Standard_Integer) const ) &FilletSurf_Builder::PCurve1OnFillet, "gives the PCurve associated to CurveOnFace1(Index) on the Fillet", py::arg("Index"));
	cls_FilletSurf_Builder.def("PCurveOnFace2", (const opencascade::handle<Geom2d_Curve> & (FilletSurf_Builder::*)(const Standard_Integer) const ) &FilletSurf_Builder::PCurveOnFace2, "gives the PCurve associated to CurveOnSup2(Index) on the support face", py::arg("Index"));
	cls_FilletSurf_Builder.def("PCurve2OnFillet", (const opencascade::handle<Geom2d_Curve> & (FilletSurf_Builder::*)(const Standard_Integer) const ) &FilletSurf_Builder::PCurve2OnFillet, "gives the PCurve associated to CurveOnSup2(Index) on the fillet", py::arg("Index"));
	cls_FilletSurf_Builder.def("FirstParameter", (Standard_Real (FilletSurf_Builder::*)() const ) &FilletSurf_Builder::FirstParameter, "gives the parameter of the fillet on the first edge.");
	cls_FilletSurf_Builder.def("LastParameter", (Standard_Real (FilletSurf_Builder::*)() const ) &FilletSurf_Builder::LastParameter, "gives the parameter of the fillet on the last edge");
	cls_FilletSurf_Builder.def("StartSectionStatus", (FilletSurf_StatusType (FilletSurf_Builder::*)() const ) &FilletSurf_Builder::StartSectionStatus, "None");
	cls_FilletSurf_Builder.def("EndSectionStatus", (FilletSurf_StatusType (FilletSurf_Builder::*)() const ) &FilletSurf_Builder::EndSectionStatus, "None");
	cls_FilletSurf_Builder.def("NbSection", (Standard_Integer (FilletSurf_Builder::*)(const Standard_Integer) const ) &FilletSurf_Builder::NbSection, "None", py::arg("IndexSurf"));
	cls_FilletSurf_Builder.def("Section", (void (FilletSurf_Builder::*)(const Standard_Integer, const Standard_Integer, opencascade::handle<Geom_TrimmedCurve> &) const ) &FilletSurf_Builder::Section, "None", py::arg("IndexSurf"), py::arg("IndexSec"), py::arg("Circ"));


}
