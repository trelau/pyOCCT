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
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <TopoDS_Face.hxx>
#include <gp_Vec.hxx>
#include <Standard_Handle.hxx>
#include <BRepAdaptor_HSurface.hxx>
#include <TopoDS_Shell.hxx>
#include <gp_Lin.hxx>
#include <TopAbs_State.hxx>
#include <Bnd_Box.hxx>
#include <IntCurvesFace_Intersector.hxx>
#include <BRepClass3d_BndBoxTree.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <BRepClass3d_SolidExplorer.hxx>
#include <gp_Pnt2d.hxx>
#include <TopExp_Explorer.hxx>
#include <BRepClass3d_MapOfInter.hxx>

void bind_BRepClass3d_SolidExplorer(py::module &mod){

py::class_<BRepClass3d_SolidExplorer, std::unique_ptr<BRepClass3d_SolidExplorer, Deleter<BRepClass3d_SolidExplorer>>> cls_BRepClass3d_SolidExplorer(mod, "BRepClass3d_SolidExplorer", "Provide an exploration of a BRep Shape for the classification. Provide access to the special UB tree to obtain fast search.");

// Constructors
cls_BRepClass3d_SolidExplorer.def(py::init<>());
cls_BRepClass3d_SolidExplorer.def(py::init<const TopoDS_Shape &>(), py::arg("S"));

// Fields

// Methods
// cls_BRepClass3d_SolidExplorer.def_static("operator new_", (void * (*)(size_t)) &BRepClass3d_SolidExplorer::operator new, "None", py::arg("theSize"));
// cls_BRepClass3d_SolidExplorer.def_static("operator delete_", (void (*)(void *)) &BRepClass3d_SolidExplorer::operator delete, "None", py::arg("theAddress"));
// cls_BRepClass3d_SolidExplorer.def_static("operator new[]_", (void * (*)(size_t)) &BRepClass3d_SolidExplorer::operator new[], "None", py::arg("theSize"));
// cls_BRepClass3d_SolidExplorer.def_static("operator delete[]_", (void (*)(void *)) &BRepClass3d_SolidExplorer::operator delete[], "None", py::arg("theAddress"));
// cls_BRepClass3d_SolidExplorer.def_static("operator new_", (void * (*)(size_t, void *)) &BRepClass3d_SolidExplorer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepClass3d_SolidExplorer.def_static("operator delete_", (void (*)(void *, void *)) &BRepClass3d_SolidExplorer::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepClass3d_SolidExplorer.def("InitShape", (void (BRepClass3d_SolidExplorer::*)(const TopoDS_Shape &)) &BRepClass3d_SolidExplorer::InitShape, "None", py::arg("S"));
cls_BRepClass3d_SolidExplorer.def("Reject", (Standard_Boolean (BRepClass3d_SolidExplorer::*)(const gp_Pnt &) const) &BRepClass3d_SolidExplorer::Reject, "Should return True if P outside of bounding vol. of the shape", py::arg("P"));
cls_BRepClass3d_SolidExplorer.def_static("FindAPointInTheFace_", [](const TopoDS_Face & F, gp_Pnt & P, Standard_Real & Param){ Standard_Boolean rv = BRepClass3d_SolidExplorer::FindAPointInTheFace(F, P, Param); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Param); }, "compute a point P in the face F. Param is a Real in ]0,1[ and is used to initialise the algorithm. For different values , different points are returned.", py::arg("F"), py::arg("P"), py::arg("Param"));
cls_BRepClass3d_SolidExplorer.def_static("FindAPointInTheFace_", [](const TopoDS_Face & F, gp_Pnt & P, Standard_Real & u, Standard_Real & v, Standard_Real & Param){ Standard_Boolean rv = BRepClass3d_SolidExplorer::FindAPointInTheFace(F, P, u, v, Param); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &, Standard_Real &>(rv, u, v, Param); }, "None", py::arg("F"), py::arg("P"), py::arg("u"), py::arg("v"), py::arg("Param"));
cls_BRepClass3d_SolidExplorer.def_static("FindAPointInTheFace_", [](const TopoDS_Face & F, gp_Pnt & P, Standard_Real & u, Standard_Real & v, Standard_Real & Param, gp_Vec & theVecD1U, gp_Vec & theVecD1V){ Standard_Boolean rv = BRepClass3d_SolidExplorer::FindAPointInTheFace(F, P, u, v, Param, theVecD1U, theVecD1V); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &, Standard_Real &>(rv, u, v, Param); }, "None", py::arg("F"), py::arg("P"), py::arg("u"), py::arg("v"), py::arg("Param"), py::arg("theVecD1U"), py::arg("theVecD1V"));
cls_BRepClass3d_SolidExplorer.def_static("FindAPointInTheFace_", [](const TopoDS_Face & F, gp_Pnt & P, Standard_Real & u, Standard_Real & v){ Standard_Boolean rv = BRepClass3d_SolidExplorer::FindAPointInTheFace(F, P, u, v); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, u, v); }, "None", py::arg("F"), py::arg("P"), py::arg("u"), py::arg("v"));
cls_BRepClass3d_SolidExplorer.def_static("FindAPointInTheFace_", (Standard_Boolean (*)(const TopoDS_Face &, gp_Pnt &)) &BRepClass3d_SolidExplorer::FindAPointInTheFace, "None", py::arg("F"), py::arg("P"));
cls_BRepClass3d_SolidExplorer.def_static("FindAPointInTheFace_", [](const TopoDS_Face & F, Standard_Real & u, Standard_Real & v){ Standard_Boolean rv = BRepClass3d_SolidExplorer::FindAPointInTheFace(F, u, v); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, u, v); }, "None", py::arg("F"), py::arg("u"), py::arg("v"));
cls_BRepClass3d_SolidExplorer.def("PointInTheFace", [](BRepClass3d_SolidExplorer &self, const TopoDS_Face & F, gp_Pnt & P, Standard_Real & u, Standard_Real & v, Standard_Real & Param, Standard_Integer & Index){ Standard_Boolean rv = self.PointInTheFace(F, P, u, v, Param, Index); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Integer &>(rv, u, v, Param, Index); }, "None", py::arg("F"), py::arg("P"), py::arg("u"), py::arg("v"), py::arg("Param"), py::arg("Index"));
cls_BRepClass3d_SolidExplorer.def("PointInTheFace", [](BRepClass3d_SolidExplorer &self, const TopoDS_Face & F, gp_Pnt & P, Standard_Real & u, Standard_Real & v, Standard_Real & Param, Standard_Integer & Index, const opencascade::handle<BRepAdaptor_HSurface> & surf, const Standard_Real u1, const Standard_Real v1, const Standard_Real u2, const Standard_Real v2){ Standard_Boolean rv = self.PointInTheFace(F, P, u, v, Param, Index, surf, u1, v1, u2, v2); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Integer &>(rv, u, v, Param, Index); }, "None", py::arg("F"), py::arg("P"), py::arg("u"), py::arg("v"), py::arg("Param"), py::arg("Index"), py::arg("surf"), py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"));
cls_BRepClass3d_SolidExplorer.def("PointInTheFace", [](BRepClass3d_SolidExplorer &self, const TopoDS_Face & F, gp_Pnt & P, Standard_Real & u, Standard_Real & v, Standard_Real & Param, Standard_Integer & Index, const opencascade::handle<BRepAdaptor_HSurface> & surf, const Standard_Real u1, const Standard_Real v1, const Standard_Real u2, const Standard_Real v2, gp_Vec & theVecD1U, gp_Vec & theVecD1V){ Standard_Boolean rv = self.PointInTheFace(F, P, u, v, Param, Index, surf, u1, v1, u2, v2, theVecD1U, theVecD1V); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Integer &>(rv, u, v, Param, Index); }, "<Index> gives point index to search from and returns point index of succeseful search", py::arg("F"), py::arg("P"), py::arg("u"), py::arg("v"), py::arg("Param"), py::arg("Index"), py::arg("surf"), py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("theVecD1U"), py::arg("theVecD1V"));
cls_BRepClass3d_SolidExplorer.def("InitShell", (void (BRepClass3d_SolidExplorer::*)()) &BRepClass3d_SolidExplorer::InitShell, "Starts an exploration of the shells.");
cls_BRepClass3d_SolidExplorer.def("MoreShell", (Standard_Boolean (BRepClass3d_SolidExplorer::*)() const) &BRepClass3d_SolidExplorer::MoreShell, "Returns True if there is a current shell.");
cls_BRepClass3d_SolidExplorer.def("NextShell", (void (BRepClass3d_SolidExplorer::*)()) &BRepClass3d_SolidExplorer::NextShell, "Sets the explorer to the next shell.");
cls_BRepClass3d_SolidExplorer.def("CurrentShell", (TopoDS_Shell (BRepClass3d_SolidExplorer::*)() const) &BRepClass3d_SolidExplorer::CurrentShell, "Returns the current shell.");
cls_BRepClass3d_SolidExplorer.def("RejectShell", (Standard_Boolean (BRepClass3d_SolidExplorer::*)(const gp_Lin &) const) &BRepClass3d_SolidExplorer::RejectShell, "Returns True if the Shell is rejected.", py::arg("L"));
cls_BRepClass3d_SolidExplorer.def("InitFace", (void (BRepClass3d_SolidExplorer::*)()) &BRepClass3d_SolidExplorer::InitFace, "Starts an exploration of the faces of the current shell.");
cls_BRepClass3d_SolidExplorer.def("MoreFace", (Standard_Boolean (BRepClass3d_SolidExplorer::*)() const) &BRepClass3d_SolidExplorer::MoreFace, "Returns True if current face in current shell.");
cls_BRepClass3d_SolidExplorer.def("NextFace", (void (BRepClass3d_SolidExplorer::*)()) &BRepClass3d_SolidExplorer::NextFace, "Sets the explorer to the next Face of the current shell.");
cls_BRepClass3d_SolidExplorer.def("CurrentFace", (TopoDS_Face (BRepClass3d_SolidExplorer::*)() const) &BRepClass3d_SolidExplorer::CurrentFace, "Returns the current face.");
cls_BRepClass3d_SolidExplorer.def("RejectFace", (Standard_Boolean (BRepClass3d_SolidExplorer::*)(const gp_Lin &) const) &BRepClass3d_SolidExplorer::RejectFace, "returns True if the face is rejected.", py::arg("L"));
cls_BRepClass3d_SolidExplorer.def("Segment", [](BRepClass3d_SolidExplorer &self, const gp_Pnt & P, gp_Lin & L, Standard_Real & Par){ Standard_Integer rv = self.Segment(P, L, Par); return std::tuple<Standard_Integer, Standard_Real &>(rv, Par); }, "Returns in <L>, <Par> a segment having at least one intersection with the shape boundary to compute intersections.", py::arg("P"), py::arg("L"), py::arg("Par"));
cls_BRepClass3d_SolidExplorer.def("OtherSegment", [](BRepClass3d_SolidExplorer &self, const gp_Pnt & P, gp_Lin & L, Standard_Real & Par){ Standard_Integer rv = self.OtherSegment(P, L, Par); return std::tuple<Standard_Integer, Standard_Real &>(rv, Par); }, "Returns in <L>, <Par> a segment having at least one intersection with the shape boundary to compute intersections.", py::arg("P"), py::arg("L"), py::arg("Par"));
cls_BRepClass3d_SolidExplorer.def("GetFaceSegmentIndex", (Standard_Integer (BRepClass3d_SolidExplorer::*)() const) &BRepClass3d_SolidExplorer::GetFaceSegmentIndex, "Returns the index of face for which last segment is calculated.");
cls_BRepClass3d_SolidExplorer.def("DumpSegment", (void (BRepClass3d_SolidExplorer::*)(const gp_Pnt &, const gp_Lin &, const Standard_Real, const TopAbs_State) const) &BRepClass3d_SolidExplorer::DumpSegment, "None", py::arg("P"), py::arg("L"), py::arg("Par"), py::arg("S"));
cls_BRepClass3d_SolidExplorer.def("Box", (const Bnd_Box & (BRepClass3d_SolidExplorer::*)() const) &BRepClass3d_SolidExplorer::Box, "None");
cls_BRepClass3d_SolidExplorer.def("GetShape", (const TopoDS_Shape & (BRepClass3d_SolidExplorer::*)() const) &BRepClass3d_SolidExplorer::GetShape, "None");
cls_BRepClass3d_SolidExplorer.def("Intersector", (IntCurvesFace_Intersector & (BRepClass3d_SolidExplorer::*)(const TopoDS_Face &) const) &BRepClass3d_SolidExplorer::Intersector, "None", py::arg("F"));
cls_BRepClass3d_SolidExplorer.def("GetTree", (const BRepClass3d_BndBoxTree & (BRepClass3d_SolidExplorer::*)()) &BRepClass3d_SolidExplorer::GetTree, "Return UB-tree instance which is used for edge / vertex checks.");
cls_BRepClass3d_SolidExplorer.def("GetMapEV", (const TopTools_IndexedMapOfShape & (BRepClass3d_SolidExplorer::*)()) &BRepClass3d_SolidExplorer::GetMapEV, "Return edge/vertices map for current shape.");
cls_BRepClass3d_SolidExplorer.def("Destroy", (void (BRepClass3d_SolidExplorer::*)()) &BRepClass3d_SolidExplorer::Destroy, "None");

// Enums

}