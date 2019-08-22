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
#include <gp_Pnt.hxx>
#include <TopoDS_Edge.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <ShapeAnalysis_DataMapOfShapeListOfReal.hxx>
#include <TopoDS_Compound.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <ShapeExtend_Status.hxx>
#include <TopoDS_Shape.hxx>
#include <ShapeAnalysis_CheckSmallFace.hxx>

void bind_ShapeAnalysis_CheckSmallFace(py::module &mod){

py::class_<ShapeAnalysis_CheckSmallFace> cls_ShapeAnalysis_CheckSmallFace(mod, "ShapeAnalysis_CheckSmallFace", "Analysis of the face size");

// Constructors
cls_ShapeAnalysis_CheckSmallFace.def(py::init<>());

// Fields

// Methods
// cls_ShapeAnalysis_CheckSmallFace.def_static("operator new_", (void * (*)(size_t)) &ShapeAnalysis_CheckSmallFace::operator new, "None", py::arg("theSize"));
// cls_ShapeAnalysis_CheckSmallFace.def_static("operator delete_", (void (*)(void *)) &ShapeAnalysis_CheckSmallFace::operator delete, "None", py::arg("theAddress"));
// cls_ShapeAnalysis_CheckSmallFace.def_static("operator new[]_", (void * (*)(size_t)) &ShapeAnalysis_CheckSmallFace::operator new[], "None", py::arg("theSize"));
// cls_ShapeAnalysis_CheckSmallFace.def_static("operator delete[]_", (void (*)(void *)) &ShapeAnalysis_CheckSmallFace::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeAnalysis_CheckSmallFace.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeAnalysis_CheckSmallFace::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeAnalysis_CheckSmallFace.def_static("operator delete_", (void (*)(void *, void *)) &ShapeAnalysis_CheckSmallFace::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeAnalysis_CheckSmallFace.def("IsSpotFace", [](ShapeAnalysis_CheckSmallFace &self, const TopoDS_Face & F, gp_Pnt & spot, Standard_Real & spotol, const Standard_Real tol){ Standard_Integer rv = self.IsSpotFace(F, spot, spotol, tol); return std::tuple<Standard_Integer, Standard_Real &>(rv, spotol); }, "Checks if a Face is as a Spot Returns 0 if not, 1 if yes, 2 if yes and all vertices are the same By default, considers the tolerance zone of its vertices A given value <tol> may be given to check a spot of this size If a Face is a Spot, its location is returned in <spot>, and <spotol> returns an equivalent tolerance, which is computed as half of max dimension of min-max box of the face", py::arg("F"), py::arg("spot"), py::arg("spotol"), py::arg("tol"));
cls_ShapeAnalysis_CheckSmallFace.def("CheckSpotFace", [](ShapeAnalysis_CheckSmallFace &self, const TopoDS_Face & a0) -> Standard_Boolean { return self.CheckSpotFace(a0); });
cls_ShapeAnalysis_CheckSmallFace.def("CheckSpotFace", (Standard_Boolean (ShapeAnalysis_CheckSmallFace::*)(const TopoDS_Face &, const Standard_Real)) &ShapeAnalysis_CheckSmallFace::CheckSpotFace, "Acts as IsSpotFace, but records in <infos> a diagnostic 'SpotFace' with the Pnt as value (data 'Location')", py::arg("F"), py::arg("tol"));
cls_ShapeAnalysis_CheckSmallFace.def("IsStripSupport", [](ShapeAnalysis_CheckSmallFace &self, const TopoDS_Face & a0) -> Standard_Boolean { return self.IsStripSupport(a0); });
cls_ShapeAnalysis_CheckSmallFace.def("IsStripSupport", (Standard_Boolean (ShapeAnalysis_CheckSmallFace::*)(const TopoDS_Face &, const Standard_Real)) &ShapeAnalysis_CheckSmallFace::IsStripSupport, "Checks if a Face lies on a Surface which is a strip So the Face is a strip. But a Face may be a strip elsewhere ..", py::arg("F"), py::arg("tol"));
cls_ShapeAnalysis_CheckSmallFace.def("CheckStripEdges", [](ShapeAnalysis_CheckSmallFace &self, const TopoDS_Edge & E1, const TopoDS_Edge & E2, const Standard_Real tol, Standard_Real & dmax){ Standard_Boolean rv = self.CheckStripEdges(E1, E2, tol, dmax); return std::tuple<Standard_Boolean, Standard_Real &>(rv, dmax); }, "Checks if two edges define a strip, i.e. distance maxi below tolerance, given or some of those of E1 and E2", py::arg("E1"), py::arg("E2"), py::arg("tol"), py::arg("dmax"));
cls_ShapeAnalysis_CheckSmallFace.def("FindStripEdges", [](ShapeAnalysis_CheckSmallFace &self, const TopoDS_Face & F, TopoDS_Edge & E1, TopoDS_Edge & E2, const Standard_Real tol, Standard_Real & dmax){ Standard_Boolean rv = self.FindStripEdges(F, E1, E2, tol, dmax); return std::tuple<Standard_Boolean, Standard_Real &>(rv, dmax); }, "Searchs for two and only two edges up tolerance Returns True if OK, false if not 2 edges If True, returns the two edges and their maximum distance", py::arg("F"), py::arg("E1"), py::arg("E2"), py::arg("tol"), py::arg("dmax"));
cls_ShapeAnalysis_CheckSmallFace.def("CheckSingleStrip", [](ShapeAnalysis_CheckSmallFace &self, const TopoDS_Face & a0, TopoDS_Edge & a1, TopoDS_Edge & a2) -> Standard_Boolean { return self.CheckSingleStrip(a0, a1, a2); });
cls_ShapeAnalysis_CheckSmallFace.def("CheckSingleStrip", (Standard_Boolean (ShapeAnalysis_CheckSmallFace::*)(const TopoDS_Face &, TopoDS_Edge &, TopoDS_Edge &, const Standard_Real)) &ShapeAnalysis_CheckSmallFace::CheckSingleStrip, "Checks if a Face is a single strip, i.e. brings two great edges which are confused on their whole length, possible other edges are small or null length", py::arg("F"), py::arg("E1"), py::arg("E2"), py::arg("tol"));
cls_ShapeAnalysis_CheckSmallFace.def("CheckStripFace", [](ShapeAnalysis_CheckSmallFace &self, const TopoDS_Face & a0, TopoDS_Edge & a1, TopoDS_Edge & a2) -> Standard_Boolean { return self.CheckStripFace(a0, a1, a2); });
cls_ShapeAnalysis_CheckSmallFace.def("CheckStripFace", (Standard_Boolean (ShapeAnalysis_CheckSmallFace::*)(const TopoDS_Face &, TopoDS_Edge &, TopoDS_Edge &, const Standard_Real)) &ShapeAnalysis_CheckSmallFace::CheckStripFace, "Checks if a Face is as a Strip Returns 0 if not or non determined, 1 if in U, 2 if in V By default, considers the tolerance zone of its edges A given value <tol> may be given to check a strip of max this width", py::arg("F"), py::arg("E1"), py::arg("E2"), py::arg("tol"));
cls_ShapeAnalysis_CheckSmallFace.def("CheckSplittingVertices", (Standard_Integer (ShapeAnalysis_CheckSmallFace::*)(const TopoDS_Face &, TopTools_DataMapOfShapeListOfShape &, ShapeAnalysis_DataMapOfShapeListOfReal &, TopoDS_Compound &)) &ShapeAnalysis_CheckSmallFace::CheckSplittingVertices, "Checks if a Face brings vertices which split it, either confused with non adjacent vertices, or confused with their projection on non adjacent edges Returns the count of found splitting vertices Each vertex then brings a diagnostic 'SplittingVertex', with data : 'Face' for the face, 'Edge' for the split edge", py::arg("F"), py::arg("MapEdges"), py::arg("MapParam"), py::arg("theAllVert"));
cls_ShapeAnalysis_CheckSmallFace.def("CheckPin", [](ShapeAnalysis_CheckSmallFace &self, const TopoDS_Face & F, Standard_Integer & whatrow, Standard_Integer & sence){ Standard_Boolean rv = self.CheckPin(F, whatrow, sence); return std::tuple<Standard_Boolean, Standard_Integer &, Standard_Integer &>(rv, whatrow, sence); }, "Checks if a Face has a pin, which can be edited No singularity : no pin, returns 0 If there is a pin, checked topics, with returned value : - 0 : nothing to do more - 1 : 'smooth', i.e. not a really sharp pin -> diagnostic 'SmoothPin' - 2 : stretched pin, i.e. is possible to relimit the face by another vertex, so that this vertex still gives a pin -> diagnostic 'StretchedPin' with location of vertex (Pnt)", py::arg("F"), py::arg("whatrow"), py::arg("sence"));
cls_ShapeAnalysis_CheckSmallFace.def("CheckTwisted", [](ShapeAnalysis_CheckSmallFace &self, const TopoDS_Face & F, Standard_Real & paramu, Standard_Real & paramv){ Standard_Boolean rv = self.CheckTwisted(F, paramu, paramv); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, paramu, paramv); }, "Checks if a Face is twisted (apart from checking Pin, i.e. it does not give information on pin, only 'it is twisted')", py::arg("F"), py::arg("paramu"), py::arg("paramv"));
cls_ShapeAnalysis_CheckSmallFace.def("CheckPinFace", [](ShapeAnalysis_CheckSmallFace &self, const TopoDS_Face & a0, TopTools_DataMapOfShapeShape & a1) -> Standard_Boolean { return self.CheckPinFace(a0, a1); });
cls_ShapeAnalysis_CheckSmallFace.def("CheckPinFace", (Standard_Boolean (ShapeAnalysis_CheckSmallFace::*)(const TopoDS_Face &, TopTools_DataMapOfShapeShape &, const Standard_Real)) &ShapeAnalysis_CheckSmallFace::CheckPinFace, "None", py::arg("F"), py::arg("mapEdges"), py::arg("toler"));
cls_ShapeAnalysis_CheckSmallFace.def("CheckPinEdges", (Standard_Boolean (ShapeAnalysis_CheckSmallFace::*)(const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Real, const Standard_Real, const Standard_Real) const) &ShapeAnalysis_CheckSmallFace::CheckPinEdges, "None", py::arg("theFirstEdge"), py::arg("theSecondEdge"), py::arg("coef1"), py::arg("coef2"), py::arg("toler"));
cls_ShapeAnalysis_CheckSmallFace.def("Status", (Standard_Boolean (ShapeAnalysis_CheckSmallFace::*)(const ShapeExtend_Status) const) &ShapeAnalysis_CheckSmallFace::Status, "Returns the status of last call to Perform() ShapeExtend_OK : face was OK, nothing done ShapeExtend_DONE1: some wires are fixed ShapeExtend_DONE2: orientation of wires fixed ShapeExtend_DONE3: missing seam added ShapeExtend_DONE4: small area wire removed ShapeExtend_DONE5: natural bounds added ShapeExtend_FAIL1: some fails during fixing wires ShapeExtend_FAIL2: cannot fix orientation of wires ShapeExtend_FAIL3: cannot add missing seam ShapeExtend_FAIL4: cannot remove small area wire", py::arg("status"));
cls_ShapeAnalysis_CheckSmallFace.def("SetTolerance", (void (ShapeAnalysis_CheckSmallFace::*)(const Standard_Real)) &ShapeAnalysis_CheckSmallFace::SetTolerance, "Sets a fixed Tolerance to check small face By default, local tolerance zone is considered Sets a fixed MaxTolerance to check small face Sets a fixed Tolerance to check small face By default, local tolerance zone is considered Unset fixed tolerance, comes back to local tolerance zones Unset fixed tolerance, comes back to local tolerance zones", py::arg("tol"));
cls_ShapeAnalysis_CheckSmallFace.def("Tolerance", (Standard_Real (ShapeAnalysis_CheckSmallFace::*)() const) &ShapeAnalysis_CheckSmallFace::Tolerance, "Returns the tolerance to check small faces, negative value if local tolerances zones are to be considered");
cls_ShapeAnalysis_CheckSmallFace.def("StatusSpot", (Standard_Boolean (ShapeAnalysis_CheckSmallFace::*)(const ShapeExtend_Status) const) &ShapeAnalysis_CheckSmallFace::StatusSpot, "None", py::arg("status"));
cls_ShapeAnalysis_CheckSmallFace.def("StatusStrip", (Standard_Boolean (ShapeAnalysis_CheckSmallFace::*)(const ShapeExtend_Status) const) &ShapeAnalysis_CheckSmallFace::StatusStrip, "None", py::arg("status"));
cls_ShapeAnalysis_CheckSmallFace.def("StatusPin", (Standard_Boolean (ShapeAnalysis_CheckSmallFace::*)(const ShapeExtend_Status) const) &ShapeAnalysis_CheckSmallFace::StatusPin, "None", py::arg("status"));
cls_ShapeAnalysis_CheckSmallFace.def("StatusTwisted", (Standard_Boolean (ShapeAnalysis_CheckSmallFace::*)(const ShapeExtend_Status) const) &ShapeAnalysis_CheckSmallFace::StatusTwisted, "None", py::arg("status"));
cls_ShapeAnalysis_CheckSmallFace.def("StatusSplitVert", (Standard_Boolean (ShapeAnalysis_CheckSmallFace::*)(const ShapeExtend_Status) const) &ShapeAnalysis_CheckSmallFace::StatusSplitVert, "None", py::arg("status"));
cls_ShapeAnalysis_CheckSmallFace.def("StatusPinFace", (Standard_Boolean (ShapeAnalysis_CheckSmallFace::*)(const ShapeExtend_Status) const) &ShapeAnalysis_CheckSmallFace::StatusPinFace, "None", py::arg("status"));
cls_ShapeAnalysis_CheckSmallFace.def("StatusPinEdges", (Standard_Boolean (ShapeAnalysis_CheckSmallFace::*)(const ShapeExtend_Status) const) &ShapeAnalysis_CheckSmallFace::StatusPinEdges, "None", py::arg("status"));

// Enums

}