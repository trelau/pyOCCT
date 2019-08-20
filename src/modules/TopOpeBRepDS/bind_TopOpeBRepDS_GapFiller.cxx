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
#include <TopOpeBRepDS_HDataStructure.hxx>
#include <TopOpeBRepDS_Interference.hxx>
#include <TopOpeBRepDS_ListOfInterference.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <TColStd_MapOfInteger.hxx>
#include <TopOpeBRepDS_GapTool.hxx>
#include <TopOpeBRepDS_Association.hxx>
#include <TopOpeBRepDS_GapFiller.hxx>

void bind_TopOpeBRepDS_GapFiller(py::module &mod){

py::class_<TopOpeBRepDS_GapFiller, std::unique_ptr<TopOpeBRepDS_GapFiller>> cls_TopOpeBRepDS_GapFiller(mod, "TopOpeBRepDS_GapFiller", "None");

// Constructors
cls_TopOpeBRepDS_GapFiller.def(py::init<const opencascade::handle<TopOpeBRepDS_HDataStructure> &>(), py::arg("HDS"));

// Fields

// Methods
// cls_TopOpeBRepDS_GapFiller.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_GapFiller::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_GapFiller.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_GapFiller::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_GapFiller.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_GapFiller::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_GapFiller.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_GapFiller::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_GapFiller.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_GapFiller::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_GapFiller.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_GapFiller::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_GapFiller.def("Perform", (void (TopOpeBRepDS_GapFiller::*)()) &TopOpeBRepDS_GapFiller::Perform, "None");
cls_TopOpeBRepDS_GapFiller.def("FindAssociatedPoints", (void (TopOpeBRepDS_GapFiller::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_GapFiller::FindAssociatedPoints, "Recherche parmi l'ensemble des points d'Interference la Liste <LI> des points qui correspondent au point d'indice <Index>", py::arg("I"), py::arg("LI"));
cls_TopOpeBRepDS_GapFiller.def("CheckConnexity", (Standard_Boolean (TopOpeBRepDS_GapFiller::*)(TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_GapFiller::CheckConnexity, "Enchaine les sections via les points d'Interferences deja associe; Renvoit dans <L> les points extremites des Lignes. Methodes pour construire la liste des Points qui peuvent correspondre a une Point donne.", py::arg("LI"));
cls_TopOpeBRepDS_GapFiller.def("AddPointsOnShape", (void (TopOpeBRepDS_GapFiller::*)(const TopoDS_Shape &, TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_GapFiller::AddPointsOnShape, "None", py::arg("S"), py::arg("LI"));
cls_TopOpeBRepDS_GapFiller.def("AddPointsOnConnexShape", (void (TopOpeBRepDS_GapFiller::*)(const TopoDS_Shape &, const TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_GapFiller::AddPointsOnConnexShape, "Methodes pour reduire la liste des Points qui peuvent correspondre a une Point donne.", py::arg("F"), py::arg("LI"));
cls_TopOpeBRepDS_GapFiller.def("FilterByFace", (void (TopOpeBRepDS_GapFiller::*)(const TopoDS_Face &, TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_GapFiller::FilterByFace, "None", py::arg("F"), py::arg("LI"));
cls_TopOpeBRepDS_GapFiller.def("FilterByEdge", (void (TopOpeBRepDS_GapFiller::*)(const TopoDS_Edge &, TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_GapFiller::FilterByEdge, "None", py::arg("E"), py::arg("LI"));
cls_TopOpeBRepDS_GapFiller.def("FilterByIncidentDistance", (void (TopOpeBRepDS_GapFiller::*)(const TopoDS_Face &, const opencascade::handle<TopOpeBRepDS_Interference> &, TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_GapFiller::FilterByIncidentDistance, "None", py::arg("F"), py::arg("I"), py::arg("LI"));
cls_TopOpeBRepDS_GapFiller.def("IsOnFace", (Standard_Boolean (TopOpeBRepDS_GapFiller::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const TopoDS_Face &) const) &TopOpeBRepDS_GapFiller::IsOnFace, "Return TRUE si I a ete obtenu par une intersection avec <F>.", py::arg("I"), py::arg("F"));
cls_TopOpeBRepDS_GapFiller.def("IsOnEdge", (Standard_Boolean (TopOpeBRepDS_GapFiller::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const TopoDS_Edge &) const) &TopOpeBRepDS_GapFiller::IsOnEdge, "Return TRUE si I ou une de ses representaions a pour support <E>. Methodes de reconstructions des geometries des point et des courbes de section", py::arg("I"), py::arg("E"));
cls_TopOpeBRepDS_GapFiller.def("BuildNewGeometries", (void (TopOpeBRepDS_GapFiller::*)()) &TopOpeBRepDS_GapFiller::BuildNewGeometries, "None");
cls_TopOpeBRepDS_GapFiller.def("ReBuildGeom", (void (TopOpeBRepDS_GapFiller::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, TColStd_MapOfInteger &)) &TopOpeBRepDS_GapFiller::ReBuildGeom, "None", py::arg("I1"), py::arg("Done"));

// Enums

}