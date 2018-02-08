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

#include <ChFiDS_SurfData.hxx>

#include <Standard_TypeDef.hxx>
#include <TopOpeBRepDS_DataStructure.hxx>
#include <Standard_Handle.hxx>
#include <ChFiDS_SurfData.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <TopAbs_Orientation.hxx>
#include <ChFiDS_Spine.hxx>
#include <gp_Pnt2d.hxx>
#include <ChFiKPart_ComputeData.hxx>
#include <ChFiKPart_ComputeData_ChAsymPlnPln.hxx>
#include <gp_Pln.hxx>
#include <gp_Lin.hxx>
#include <ChFiKPart_ComputeData_ChPlnPln.hxx>
#include <ChFiKPart_ComputeData_CS.hxx>
#include <gp_Cylinder.hxx>
#include <gp_Circ.hxx>
#include <ChFiKPart_ComputeData_Fcts.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <GeomAdaptor_Curve.hxx>
#include <GeomAdaptor_Surface.hxx>
#include <Geom2d_Curve.hxx>
#include <Geom_Curve.hxx>
#include <Geom_Surface.hxx>
#include <ChFiKPart_ComputeData_FilPlnPln.hxx>
#include <ChFiKPart_ComputeData_Rotule.hxx>
#include <ChFiKPart_ComputeData_Sphere.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_DataMap.hxx>
#include <ChFiKPart_RstMap.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(ChFiKPart, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TopOpeBRepDS");
	py::module::import("OCCT.ChFiDS");
	py::module::import("OCCT.Adaptor3d");
	py::module::import("OCCT.TopAbs");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.Geom2d");
	py::module::import("OCCT.GeomAdaptor");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS
	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiKPart_ComputeData_ChAsymPlnPln.hxx
	mod.def("ChFiKPart_MakeChAsym", (Standard_Boolean (*)(TopOpeBRepDS_DataStructure &, const opencascade::handle<ChFiDS_SurfData> &, const gp_Pln &, const gp_Pln &, const TopAbs_Orientation, const TopAbs_Orientation, const Standard_Real, const Standard_Real, const gp_Lin &, const Standard_Real, const TopAbs_Orientation, const Standard_Boolean)) &ChFiKPart_MakeChAsym, "None", py::arg("DStr"), py::arg("Data"), py::arg("Pl1"), py::arg("Pl2"), py::arg("Or1"), py::arg("Or2"), py::arg("Dis"), py::arg("Angle"), py::arg("Spine"), py::arg("First"), py::arg("Of1"), py::arg("DisOnP1"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiKPart_ComputeData_ChPlnPln.hxx
	mod.def("ChFiKPart_MakeChamfer", (Standard_Boolean (*)(TopOpeBRepDS_DataStructure &, const opencascade::handle<ChFiDS_SurfData> &, const gp_Pln &, const gp_Pln &, const TopAbs_Orientation, const TopAbs_Orientation, const Standard_Real, const Standard_Real, const gp_Lin &, const Standard_Real, const TopAbs_Orientation)) &ChFiKPart_MakeChamfer, "None", py::arg("DStr"), py::arg("Data"), py::arg("Pl1"), py::arg("Pl2"), py::arg("Or1"), py::arg("Or2"), py::arg("Dis1"), py::arg("Dis2"), py::arg("Spine"), py::arg("First"), py::arg("Of1"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiKPart_ComputeData_CS.hxx
	mod.def("ChFiKPart_CornerSpine", (void (*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const gp_Pnt2d &, const gp_Pnt2d &, const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Real, gp_Cylinder &, gp_Circ &, Standard_Real &, Standard_Real &)) &ChFiKPart_CornerSpine, "None", py::arg("S1"), py::arg("S2"), py::arg("P1S1"), py::arg("P2S1"), py::arg("P1S2"), py::arg("P2S2"), py::arg("R"), py::arg("cyl"), py::arg("circ"), py::arg("First"), py::arg("Last"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiKPart_ComputeData_Fcts.hxx
	mod.def("ChFiKPart_InPeriod", (Standard_Real (*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &ChFiKPart_InPeriod, "None", py::arg("U"), py::arg("UFirst"), py::arg("ULast"), py::arg("Eps"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiKPart_ComputeData_Fcts.hxx
	mod.def("ChFiKPart_PCurve", (opencascade::handle<Geom2d_BSplineCurve> (*)(const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Real, const Standard_Real)) &ChFiKPart_PCurve, "None", py::arg("UV1"), py::arg("UV2"), py::arg("Pardeb"), py::arg("Parfin"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiKPart_ComputeData_Fcts.hxx
	mod.def("ChFiKPart_ProjPC", (void (*)(const GeomAdaptor_Curve &, const GeomAdaptor_Surface &, opencascade::handle<Geom2d_Curve> &)) &ChFiKPart_ProjPC, "None", py::arg("Cg"), py::arg("Sg"), py::arg("Pcurv"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiKPart_ComputeData_Fcts.hxx
	mod.def("ChFiKPart_IndexCurveInDS", (Standard_Integer (*)(const opencascade::handle<Geom_Curve> &, TopOpeBRepDS_DataStructure &)) &ChFiKPart_IndexCurveInDS, "None", py::arg("C"), py::arg("DStr"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiKPart_ComputeData_Fcts.hxx
	mod.def("ChFiKPart_IndexSurfaceInDS", (Standard_Integer (*)(const opencascade::handle<Geom_Surface> &, TopOpeBRepDS_DataStructure &)) &ChFiKPart_IndexSurfaceInDS, "None", py::arg("S"), py::arg("DStr"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiKPart_ComputeData_FilPlnPln.hxx
	mod.def("ChFiKPart_MakeFillet", (Standard_Boolean (*)(TopOpeBRepDS_DataStructure &, const opencascade::handle<ChFiDS_SurfData> &, const gp_Pln &, const gp_Pln &, const TopAbs_Orientation, const TopAbs_Orientation, const Standard_Real, const gp_Lin &, const Standard_Real, const TopAbs_Orientation)) &ChFiKPart_MakeFillet, "None", py::arg("DStr"), py::arg("Data"), py::arg("Pl1"), py::arg("Pl2"), py::arg("Or1"), py::arg("Or2"), py::arg("Radius"), py::arg("Spine"), py::arg("First"), py::arg("Of1"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiKPart_ComputeData_Rotule.hxx
	mod.def("ChFiKPart_MakeRotule", (Standard_Boolean (*)(TopOpeBRepDS_DataStructure &, const opencascade::handle<ChFiDS_SurfData> &, const gp_Pln &, const gp_Pln &, const gp_Pln &, const TopAbs_Orientation, const TopAbs_Orientation, const TopAbs_Orientation, const Standard_Real, const TopAbs_Orientation)) &ChFiKPart_MakeRotule, "None", py::arg("DStr"), py::arg("Data"), py::arg("pl"), py::arg("pl1"), py::arg("pl2"), py::arg("opl"), py::arg("opl1"), py::arg("opl2"), py::arg("r"), py::arg("ofpl"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiKPart_ComputeData_Sphere.hxx
	mod.def("ChFiKPart_Sphere", (Standard_Boolean (*)(TopOpeBRepDS_DataStructure &, const opencascade::handle<ChFiDS_SurfData> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const TopAbs_Orientation, const TopAbs_Orientation, const TopAbs_Orientation, const TopAbs_Orientation, const Standard_Real, const gp_Pnt2d &, const gp_Pnt2d &, const gp_Pnt2d &)) &ChFiKPart_Sphere, "None", py::arg("DStr"), py::arg("Data"), py::arg("S1"), py::arg("S2"), py::arg("OrFace1"), py::arg("OrFace2"), py::arg("Or1"), py::arg("Or2"), py::arg("Rad"), py::arg("PS1"), py::arg("P1S2"), py::arg("P2S2"));


	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiKPart_ComputeData.hxx
	py::class_<ChFiKPart_ComputeData, std::unique_ptr<ChFiKPart_ComputeData, Deleter<ChFiKPart_ComputeData>>> cls_ChFiKPart_ComputeData(mod, "ChFiKPart_ComputeData", "Methodes de classe permettant de remplir une SurfData dans les cas particuliers de conges suivants: - cylindre entre 2 surfaces planes, - tore/sphere entre un plan et un cylindre othogonal, - tore/sphere entre un plan et un cone othogonal,");
	cls_ChFiKPart_ComputeData.def(py::init<>());
	cls_ChFiKPart_ComputeData.def_static("Compute_", (Standard_Boolean (*)(TopOpeBRepDS_DataStructure &, opencascade::handle<ChFiDS_SurfData> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const TopAbs_Orientation, const TopAbs_Orientation, const opencascade::handle<ChFiDS_Spine> &, const Standard_Integer)) &ChFiKPart_ComputeData::Compute, "Computes a simple fillet in several particular cases.", py::arg("DStr"), py::arg("Data"), py::arg("S1"), py::arg("S2"), py::arg("Or1"), py::arg("Or2"), py::arg("Sp"), py::arg("Iedge"));
	cls_ChFiKPart_ComputeData.def_static("ComputeCorner_", (Standard_Boolean (*)(TopOpeBRepDS_DataStructure &, const opencascade::handle<ChFiDS_SurfData> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const TopAbs_Orientation, const TopAbs_Orientation, const TopAbs_Orientation, const TopAbs_Orientation, const Standard_Real, const Standard_Real, const gp_Pnt2d &, const gp_Pnt2d &, const gp_Pnt2d &, const gp_Pnt2d &)) &ChFiKPart_ComputeData::ComputeCorner, "Computes a toric or spheric corner fillet.", py::arg("DStr"), py::arg("Data"), py::arg("S1"), py::arg("S2"), py::arg("OrFace1"), py::arg("OrFace2"), py::arg("Or1"), py::arg("Or2"), py::arg("minRad"), py::arg("majRad"), py::arg("P1S1"), py::arg("P2S1"), py::arg("P1S2"), py::arg("P2S2"));
	cls_ChFiKPart_ComputeData.def_static("ComputeCorner_", (Standard_Boolean (*)(TopOpeBRepDS_DataStructure &, const opencascade::handle<ChFiDS_SurfData> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const TopAbs_Orientation, const TopAbs_Orientation, const TopAbs_Orientation, const TopAbs_Orientation, const Standard_Real, const gp_Pnt2d &, const gp_Pnt2d &, const gp_Pnt2d &)) &ChFiKPart_ComputeData::ComputeCorner, "Computes spheric corner fillet with non iso pcurve on S2.", py::arg("DStr"), py::arg("Data"), py::arg("S1"), py::arg("S2"), py::arg("OrFace1"), py::arg("OrFace2"), py::arg("Or1"), py::arg("Or2"), py::arg("Rad"), py::arg("PS1"), py::arg("P1S2"), py::arg("P2S2"));
	cls_ChFiKPart_ComputeData.def_static("ComputeCorner_", (Standard_Boolean (*)(TopOpeBRepDS_DataStructure &, const opencascade::handle<ChFiDS_SurfData> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const TopAbs_Orientation, const TopAbs_Orientation, const TopAbs_Orientation, const TopAbs_Orientation, const Standard_Real)) &ChFiKPart_ComputeData::ComputeCorner, "Computes a toric corner rotule.", py::arg("DStr"), py::arg("Data"), py::arg("S"), py::arg("S1"), py::arg("S2"), py::arg("OfS"), py::arg("OS"), py::arg("OS1"), py::arg("OS2"), py::arg("Radius"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiKPart_RstMap.hxx
	bind_NCollection_DataMap<int, opencascade::handle<Adaptor2d_HCurve2d>, NCollection_DefaultHasher<int> >(mod, "ChFiKPart_RstMap");

	/* FIXME

	*/


}
