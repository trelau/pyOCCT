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
#include <TopoDS_Face.hxx>
#include <IntTools_SequenceOfCurves.hxx>
#include <IntTools_SequenceOfPntOn2Faces.hxx>
#include <IntSurf_ListOfPntOn2S.hxx>
#include <Standard_Handle.hxx>
#include <IntTools_Context.hxx>
#include <Adaptor3d_TopolTool.hxx>
#include <IntPatch_Intersection.hxx>
#include <GeomInt_LineConstructor.hxx>
#include <GeomAdaptor_HSurface.hxx>
#include <IntTools_FaceFace.hxx>

void bind_IntTools_FaceFace(py::module &mod){

py::class_<IntTools_FaceFace> cls_IntTools_FaceFace(mod, "IntTools_FaceFace", "This class provides the intersection of face's underlying surfaces.");

// Constructors
cls_IntTools_FaceFace.def(py::init<>());

// Fields

// Methods
// cls_IntTools_FaceFace.def_static("operator new_", (void * (*)(size_t)) &IntTools_FaceFace::operator new, "None", py::arg("theSize"));
// cls_IntTools_FaceFace.def_static("operator delete_", (void (*)(void *)) &IntTools_FaceFace::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_FaceFace.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_FaceFace::operator new[], "None", py::arg("theSize"));
// cls_IntTools_FaceFace.def_static("operator delete[]_", (void (*)(void *)) &IntTools_FaceFace::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_FaceFace.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_FaceFace::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_FaceFace.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_FaceFace::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_FaceFace.def("SetParameters", (void (IntTools_FaceFace::*)(const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Real)) &IntTools_FaceFace::SetParameters, "Modifier", py::arg("ApproxCurves"), py::arg("ComputeCurveOnS1"), py::arg("ComputeCurveOnS2"), py::arg("ApproximationTolerance"));
cls_IntTools_FaceFace.def("Perform", (void (IntTools_FaceFace::*)(const TopoDS_Face &, const TopoDS_Face &)) &IntTools_FaceFace::Perform, "Intersects underliing surfaces of F1 and F2 Use sum of tolerance of F1 and F2 as intersection criteria", py::arg("F1"), py::arg("F2"));
cls_IntTools_FaceFace.def("IsDone", (Standard_Boolean (IntTools_FaceFace::*)() const) &IntTools_FaceFace::IsDone, "Returns True if the intersection was successful");
cls_IntTools_FaceFace.def("Lines", (const IntTools_SequenceOfCurves & (IntTools_FaceFace::*)() const) &IntTools_FaceFace::Lines, "Returns sequence of 3d curves as result of intersection");
cls_IntTools_FaceFace.def("Points", (const IntTools_SequenceOfPntOn2Faces & (IntTools_FaceFace::*)() const) &IntTools_FaceFace::Points, "Returns sequence of 3d curves as result of intersection");
cls_IntTools_FaceFace.def("Face1", (const TopoDS_Face & (IntTools_FaceFace::*)() const) &IntTools_FaceFace::Face1, "Returns first of processed faces");
cls_IntTools_FaceFace.def("Face2", (const TopoDS_Face & (IntTools_FaceFace::*)() const) &IntTools_FaceFace::Face2, "Returns second of processed faces");
cls_IntTools_FaceFace.def("TangentFaces", (Standard_Boolean (IntTools_FaceFace::*)() const) &IntTools_FaceFace::TangentFaces, "Returns True if faces are tangent");
cls_IntTools_FaceFace.def("PrepareLines3D", [](IntTools_FaceFace &self) -> void { return self.PrepareLines3D(); });
cls_IntTools_FaceFace.def("PrepareLines3D", (void (IntTools_FaceFace::*)(const Standard_Boolean)) &IntTools_FaceFace::PrepareLines3D, "Provides post-processing the result lines. <bToSplit> - the flag. In case of <bToSplit> is true the closed 3D-curves will be splitted on parts. In case of <bToSplit> is false the closed 3D-curves remain untouched.", py::arg("bToSplit"));
cls_IntTools_FaceFace.def("SetList", (void (IntTools_FaceFace::*)(IntSurf_ListOfPntOn2S &)) &IntTools_FaceFace::SetList, "None", py::arg("ListOfPnts"));
cls_IntTools_FaceFace.def("SetContext", (void (IntTools_FaceFace::*)(const opencascade::handle<IntTools_Context> &)) &IntTools_FaceFace::SetContext, "Sets the intersecton context", py::arg("aContext"));
cls_IntTools_FaceFace.def("SetFuzzyValue", (void (IntTools_FaceFace::*)(const Standard_Real)) &IntTools_FaceFace::SetFuzzyValue, "Sets the Fuzzy value", py::arg("theFuzz"));
cls_IntTools_FaceFace.def("FuzzyValue", (Standard_Real (IntTools_FaceFace::*)() const) &IntTools_FaceFace::FuzzyValue, "Returns Fuzzy value");
cls_IntTools_FaceFace.def("Context", (const opencascade::handle<IntTools_Context> & (IntTools_FaceFace::*)() const) &IntTools_FaceFace::Context, "Gets the intersecton context");

// Enums

}