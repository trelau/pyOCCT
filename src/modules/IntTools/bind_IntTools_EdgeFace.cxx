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
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <IntTools_Range.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IntTools_Context.hxx>
#include <Precision.hxx>
#include <IntTools_SequenceOfCommonPrts.hxx>
#include <gp_Pnt.hxx>
#include <BRepAdaptor_Surface.hxx>
#include <IntTools_CommonPrt.hxx>
#include <BRepAdaptor_Curve.hxx>
#include <IntTools_EdgeFace.hxx>

void bind_IntTools_EdgeFace(py::module &mod){

py::class_<IntTools_EdgeFace, std::unique_ptr<IntTools_EdgeFace>> cls_IntTools_EdgeFace(mod, "IntTools_EdgeFace", "The class provides Edge/Face intersection algorithm to determine common parts between edge and face in 3-d space. Common parts between Edge and Face can be: - Vertices - in case of intersection or touching; - Edge - in case of full coincidence of the edge with the face.");

// Constructors
cls_IntTools_EdgeFace.def(py::init<>());

// Fields

// Methods
// cls_IntTools_EdgeFace.def_static("operator new_", (void * (*)(size_t)) &IntTools_EdgeFace::operator new, "None", py::arg("theSize"));
// cls_IntTools_EdgeFace.def_static("operator delete_", (void (*)(void *)) &IntTools_EdgeFace::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_EdgeFace.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_EdgeFace::operator new[], "None", py::arg("theSize"));
// cls_IntTools_EdgeFace.def_static("operator delete[]_", (void (*)(void *)) &IntTools_EdgeFace::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_EdgeFace.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_EdgeFace::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_EdgeFace.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_EdgeFace::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_EdgeFace.def("SetEdge", (void (IntTools_EdgeFace::*)(const TopoDS_Edge &)) &IntTools_EdgeFace::SetEdge, "Sets the edge for intersection", py::arg("theEdge"));
cls_IntTools_EdgeFace.def("Edge", (const TopoDS_Edge & (IntTools_EdgeFace::*)() const) &IntTools_EdgeFace::Edge, "Returns the edge");
cls_IntTools_EdgeFace.def("SetFace", (void (IntTools_EdgeFace::*)(const TopoDS_Face &)) &IntTools_EdgeFace::SetFace, "Sets the face for intersection", py::arg("theFace"));
cls_IntTools_EdgeFace.def("Face", (const TopoDS_Face & (IntTools_EdgeFace::*)() const) &IntTools_EdgeFace::Face, "Returns the face");
cls_IntTools_EdgeFace.def("SetRange", (void (IntTools_EdgeFace::*)(const IntTools_Range &)) &IntTools_EdgeFace::SetRange, "Sets the boundaries for the edge. The algorithm processes edge inside these boundaries.", py::arg("theRange"));
cls_IntTools_EdgeFace.def("SetRange", (void (IntTools_EdgeFace::*)(const Standard_Real, const Standard_Real)) &IntTools_EdgeFace::SetRange, "Sets the boundaries for the edge. The algorithm processes edge inside these boundaries.", py::arg("theFirst"), py::arg("theLast"));
cls_IntTools_EdgeFace.def("Range", (const IntTools_Range & (IntTools_EdgeFace::*)() const) &IntTools_EdgeFace::Range, "Returns intersection range of the edge");
cls_IntTools_EdgeFace.def("SetContext", (void (IntTools_EdgeFace::*)(const opencascade::handle<IntTools_Context> &)) &IntTools_EdgeFace::SetContext, "Sets the intersection context", py::arg("theContext"));
cls_IntTools_EdgeFace.def("Context", (const opencascade::handle<IntTools_Context> & (IntTools_EdgeFace::*)() const) &IntTools_EdgeFace::Context, "Returns the intersection context");
cls_IntTools_EdgeFace.def("SetFuzzyValue", (void (IntTools_EdgeFace::*)(const Standard_Real)) &IntTools_EdgeFace::SetFuzzyValue, "Sets the Fuzzy value", py::arg("theFuzz"));
cls_IntTools_EdgeFace.def("FuzzyValue", (Standard_Real (IntTools_EdgeFace::*)() const) &IntTools_EdgeFace::FuzzyValue, "Returns the Fuzzy value");
cls_IntTools_EdgeFace.def("UseQuickCoincidenceCheck", (void (IntTools_EdgeFace::*)(const Standard_Boolean)) &IntTools_EdgeFace::UseQuickCoincidenceCheck, "Sets the flag for quick coincidence check. It is safe to use the quick check for coincidence only if both of the following conditions are met: - The vertices of edge are lying on the face; - The edge does not intersect the boundaries of the face on the given range.", py::arg("theFlag"));
cls_IntTools_EdgeFace.def("IsCoincidenceCheckedQuickly", (Standard_Boolean (IntTools_EdgeFace::*)()) &IntTools_EdgeFace::IsCoincidenceCheckedQuickly, "Returns the flag myQuickCoincidenceCheck");
cls_IntTools_EdgeFace.def("Perform", (void (IntTools_EdgeFace::*)()) &IntTools_EdgeFace::Perform, "Launches the process");
cls_IntTools_EdgeFace.def("IsDone", (Standard_Boolean (IntTools_EdgeFace::*)() const) &IntTools_EdgeFace::IsDone, "Returns TRUE if computation was successful. Otherwise returns FALSE.");
cls_IntTools_EdgeFace.def("ErrorStatus", (Standard_Integer (IntTools_EdgeFace::*)() const) &IntTools_EdgeFace::ErrorStatus, "Returns the code of completion: 0 - means successful completion; 1 - the process was not started; 2,3 - invalid source data for the algorithm; 4 - projection failed.");
cls_IntTools_EdgeFace.def("CommonParts", (const IntTools_SequenceOfCommonPrts & (IntTools_EdgeFace::*)() const) &IntTools_EdgeFace::CommonParts, "Returns resulting common parts");

// Enums

}