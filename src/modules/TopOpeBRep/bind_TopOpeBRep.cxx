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
#include <Standard_OStream.hxx>
#include <TopOpeBRep_TypeLineCurve.hxx>
#include <TopOpeBRep_VPointInter.hxx>
#include <TopOpeBRep_VPointInterIterator.hxx>
#include <TopOpeBRep_WPointInter.hxx>
#include <TopOpeBRep_WPointInterIterator.hxx>
#include <TopOpeBRep_LineInter.hxx>
#include <TopOpeBRep_Hctxff2d.hxx>
#include <TopOpeBRep_Hctxee2d.hxx>
#include <TopOpeBRep_Point2d.hxx>
#include <TopOpeBRep_PointClassifier.hxx>
#include <TopOpeBRep_VPointInterClassifier.hxx>
#include <TopOpeBRep_GeomTool.hxx>
#include <TopOpeBRep_FacesIntersector.hxx>
#include <TopOpeBRep_EdgesIntersector.hxx>
#include <TopOpeBRep_FaceEdgeIntersector.hxx>
#include <TopOpeBRep_ShapeScanner.hxx>
#include <TopOpeBRep_ShapeIntersector.hxx>
#include <TopOpeBRep_ShapeIntersector2d.hxx>
#include <TopOpeBRep_PointGeomTool.hxx>
#include <TopOpeBRep_FFTransitionTool.hxx>
#include <TopOpeBRep_Bipoint.hxx>
#include <TopOpeBRep_FacesFiller.hxx>
#include <TopOpeBRep_FFDumper.hxx>
#include <TopOpeBRep_EdgesFiller.hxx>
#include <TopOpeBRep_FaceEdgeFiller.hxx>
#include <TopOpeBRep_DSFiller.hxx>
#include <TopOpeBRep.hxx>

void bind_TopOpeBRep(py::module &mod){

py::class_<TopOpeBRep, std::unique_ptr<TopOpeBRep, Deleter<TopOpeBRep>>> cls_TopOpeBRep(mod, "TopOpeBRep", "This package provides the topological operations on the BRep data structure.");

// Constructors

// Fields

// Methods
// cls_TopOpeBRep.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRep::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRep.def_static("operator delete_", (void (*)(void *)) &TopOpeBRep::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRep.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRep::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRep.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRep::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRep.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRep::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRep.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRep::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRep.def_static("Print_", (Standard_OStream & (*)(const TopOpeBRep_TypeLineCurve, Standard_OStream &)) &TopOpeBRep::Print, "Prints the name of <TLC> as a String on the Stream <S> and returns <S>.", py::arg("TLC"), py::arg("OS"));

// Enums

}