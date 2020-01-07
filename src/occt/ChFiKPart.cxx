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
#include <Standard_TypeDef.hxx>
#include <TopOpeBRepDS_DataStructure.hxx>
#include <Standard_Handle.hxx>
#include <ChFiDS_SurfData.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <TopAbs_Orientation.hxx>
#include <ChFiDS_Spine.hxx>
#include <gp_Pnt2d.hxx>
#include <ChFiKPart_ComputeData.hxx>
#include <NCollection_DataMap.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <TColStd_MapIntegerHasher.hxx>
#include <ChFiKPart_RstMap.hxx>
#include <bind_NCollection_DataMap.hxx>

PYBIND11_MODULE(ChFiKPart, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TopOpeBRepDS");
py::module::import("OCCT.ChFiDS");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.gp");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Adaptor2d");
py::module::import("OCCT.TColStd");

// CLASS: CHFIKPART_COMPUTEDATA
py::class_<ChFiKPart_ComputeData> cls_ChFiKPart_ComputeData(mod, "ChFiKPart_ComputeData", "Methodes de classe permettant de remplir une SurfData dans les cas particuliers de conges suivants: - cylindre entre 2 surfaces planes, - tore/sphere entre un plan et un cylindre othogonal, - tore/sphere entre un plan et un cone othogonal,");

// Constructors
cls_ChFiKPart_ComputeData.def(py::init<>());

// Methods
// cls_ChFiKPart_ComputeData.def_static("operator new_", (void * (*)(size_t)) &ChFiKPart_ComputeData::operator new, "None", py::arg("theSize"));
// cls_ChFiKPart_ComputeData.def_static("operator delete_", (void (*)(void *)) &ChFiKPart_ComputeData::operator delete, "None", py::arg("theAddress"));
// cls_ChFiKPart_ComputeData.def_static("operator new[]_", (void * (*)(size_t)) &ChFiKPart_ComputeData::operator new[], "None", py::arg("theSize"));
// cls_ChFiKPart_ComputeData.def_static("operator delete[]_", (void (*)(void *)) &ChFiKPart_ComputeData::operator delete[], "None", py::arg("theAddress"));
// cls_ChFiKPart_ComputeData.def_static("operator new_", (void * (*)(size_t, void *)) &ChFiKPart_ComputeData::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ChFiKPart_ComputeData.def_static("operator delete_", (void (*)(void *, void *)) &ChFiKPart_ComputeData::operator delete, "None", py::arg(""), py::arg(""));
cls_ChFiKPart_ComputeData.def_static("Compute_", (Standard_Boolean (*)(TopOpeBRepDS_DataStructure &, opencascade::handle<ChFiDS_SurfData> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const TopAbs_Orientation, const TopAbs_Orientation, const opencascade::handle<ChFiDS_Spine> &, const Standard_Integer)) &ChFiKPart_ComputeData::Compute, "Computes a simple fillet in several particular cases.", py::arg("DStr"), py::arg("Data"), py::arg("S1"), py::arg("S2"), py::arg("Or1"), py::arg("Or2"), py::arg("Sp"), py::arg("Iedge"));
cls_ChFiKPart_ComputeData.def_static("ComputeCorner_", (Standard_Boolean (*)(TopOpeBRepDS_DataStructure &, const opencascade::handle<ChFiDS_SurfData> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const TopAbs_Orientation, const TopAbs_Orientation, const TopAbs_Orientation, const TopAbs_Orientation, const Standard_Real, const Standard_Real, const gp_Pnt2d &, const gp_Pnt2d &, const gp_Pnt2d &, const gp_Pnt2d &)) &ChFiKPart_ComputeData::ComputeCorner, "Computes a toric or spheric corner fillet.", py::arg("DStr"), py::arg("Data"), py::arg("S1"), py::arg("S2"), py::arg("OrFace1"), py::arg("OrFace2"), py::arg("Or1"), py::arg("Or2"), py::arg("minRad"), py::arg("majRad"), py::arg("P1S1"), py::arg("P2S1"), py::arg("P1S2"), py::arg("P2S2"));
cls_ChFiKPart_ComputeData.def_static("ComputeCorner_", (Standard_Boolean (*)(TopOpeBRepDS_DataStructure &, const opencascade::handle<ChFiDS_SurfData> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const TopAbs_Orientation, const TopAbs_Orientation, const TopAbs_Orientation, const TopAbs_Orientation, const Standard_Real, const gp_Pnt2d &, const gp_Pnt2d &, const gp_Pnt2d &)) &ChFiKPart_ComputeData::ComputeCorner, "Computes spheric corner fillet with non iso pcurve on S2.", py::arg("DStr"), py::arg("Data"), py::arg("S1"), py::arg("S2"), py::arg("OrFace1"), py::arg("OrFace2"), py::arg("Or1"), py::arg("Or2"), py::arg("Rad"), py::arg("PS1"), py::arg("P1S2"), py::arg("P2S2"));
cls_ChFiKPart_ComputeData.def_static("ComputeCorner_", (Standard_Boolean (*)(TopOpeBRepDS_DataStructure &, const opencascade::handle<ChFiDS_SurfData> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const TopAbs_Orientation, const TopAbs_Orientation, const TopAbs_Orientation, const TopAbs_Orientation, const Standard_Real)) &ChFiKPart_ComputeData::ComputeCorner, "Computes a toric corner rotule.", py::arg("DStr"), py::arg("Data"), py::arg("S"), py::arg("S1"), py::arg("S2"), py::arg("OfS"), py::arg("OS"), py::arg("OS1"), py::arg("OS2"), py::arg("Radius"));

// TYPEDEF: CHFIKPART_RSTMAP
bind_NCollection_DataMap<int, opencascade::handle<Adaptor2d_HCurve2d>, NCollection_DefaultHasher<int> >(mod, "ChFiKPart_RstMap", py::module_local(false));

// TYPEDEF: CHFIKPART_DATAMAPITERATOROFRSTMAP


}
