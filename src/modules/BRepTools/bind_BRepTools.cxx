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
#include <TopoDS_Face.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Edge.hxx>
#include <Bnd_Box2d.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Shell.hxx>
#include <TopoDS_Solid.hxx>
#include <TopoDS_CompSolid.hxx>
#include <TopoDS_Compound.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Handle.hxx>
#include <Message_ProgressIndicator.hxx>
#include <Standard_IStream.hxx>
#include <BRep_Builder.hxx>
#include <Geom_Curve.hxx>
#include <Geom2d_Curve.hxx>
#include <Geom_Surface.hxx>
#include <BRepTools_WireExplorer.hxx>
#include <BRepTools_Modification.hxx>
#include <BRepTools_Modifier.hxx>
#include <BRepTools_TrsfModification.hxx>
#include <BRepTools_NurbsConvertModification.hxx>
#include <BRepTools_GTrsfModification.hxx>
#include <BRepTools_Substitution.hxx>
#include <BRepTools_Quilt.hxx>
#include <BRepTools_ShapeSet.hxx>
#include <BRepTools_ReShape.hxx>
#include <BRepTools.hxx>

void bind_BRepTools(py::module &mod){

py::class_<BRepTools, std::unique_ptr<BRepTools>> cls_BRepTools(mod, "BRepTools", "The BRepTools package provides utilities for BRep data structures.");

// Constructors

// Fields

// Methods
// cls_BRepTools.def_static("operator new_", (void * (*)(size_t)) &BRepTools::operator new, "None", py::arg("theSize"));
// cls_BRepTools.def_static("operator delete_", (void (*)(void *)) &BRepTools::operator delete, "None", py::arg("theAddress"));
// cls_BRepTools.def_static("operator new[]_", (void * (*)(size_t)) &BRepTools::operator new[], "None", py::arg("theSize"));
// cls_BRepTools.def_static("operator delete[]_", (void (*)(void *)) &BRepTools::operator delete[], "None", py::arg("theAddress"));
// cls_BRepTools.def_static("operator new_", (void * (*)(size_t, void *)) &BRepTools::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepTools.def_static("operator delete_", (void (*)(void *, void *)) &BRepTools::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepTools.def_static("UVBounds_", [](const TopoDS_Face & F, Standard_Real & UMin, Standard_Real & UMax, Standard_Real & VMin, Standard_Real & VMax){ BRepTools::UVBounds(F, UMin, UMax, VMin, VMax); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(UMin, UMax, VMin, VMax); }, "Returns in UMin, UMax, VMin, VMax the bounding values in the parametric space of F.", py::arg("F"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
cls_BRepTools.def_static("UVBounds_", [](const TopoDS_Face & F, const TopoDS_Wire & W, Standard_Real & UMin, Standard_Real & UMax, Standard_Real & VMin, Standard_Real & VMax){ BRepTools::UVBounds(F, W, UMin, UMax, VMin, VMax); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(UMin, UMax, VMin, VMax); }, "Returns in UMin, UMax, VMin, VMax the bounding values of the wire in the parametric space of F.", py::arg("F"), py::arg("W"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
cls_BRepTools.def_static("UVBounds_", [](const TopoDS_Face & F, const TopoDS_Edge & E, Standard_Real & UMin, Standard_Real & UMax, Standard_Real & VMin, Standard_Real & VMax){ BRepTools::UVBounds(F, E, UMin, UMax, VMin, VMax); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(UMin, UMax, VMin, VMax); }, "Returns in UMin, UMax, VMin, VMax the bounding values of the edge in the parametric space of F.", py::arg("F"), py::arg("E"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
cls_BRepTools.def_static("AddUVBounds_", (void (*)(const TopoDS_Face &, Bnd_Box2d &)) &BRepTools::AddUVBounds, "Adds to the box <B> the bounding values in the parametric space of F.", py::arg("F"), py::arg("B"));
cls_BRepTools.def_static("AddUVBounds_", (void (*)(const TopoDS_Face &, const TopoDS_Wire &, Bnd_Box2d &)) &BRepTools::AddUVBounds, "Adds to the box <B> the bounding values of the wire in the parametric space of F.", py::arg("F"), py::arg("W"), py::arg("B"));
cls_BRepTools.def_static("AddUVBounds_", (void (*)(const TopoDS_Face &, const TopoDS_Edge &, Bnd_Box2d &)) &BRepTools::AddUVBounds, "Adds to the box <B> the bounding values of the edge in the parametric space of F.", py::arg("F"), py::arg("E"), py::arg("B"));
cls_BRepTools.def_static("Update_", (void (*)(const TopoDS_Vertex &)) &BRepTools::Update, "Update a vertex (nothing is done)", py::arg("V"));
cls_BRepTools.def_static("Update_", (void (*)(const TopoDS_Edge &)) &BRepTools::Update, "Update an edge, compute 2d bounding boxes.", py::arg("E"));
cls_BRepTools.def_static("Update_", (void (*)(const TopoDS_Wire &)) &BRepTools::Update, "Update a wire (nothing is done)", py::arg("W"));
cls_BRepTools.def_static("Update_", (void (*)(const TopoDS_Face &)) &BRepTools::Update, "Update a Face, update UV points.", py::arg("F"));
cls_BRepTools.def_static("Update_", (void (*)(const TopoDS_Shell &)) &BRepTools::Update, "Update a shell (nothing is done)", py::arg("S"));
cls_BRepTools.def_static("Update_", (void (*)(const TopoDS_Solid &)) &BRepTools::Update, "Update a solid (nothing is done)", py::arg("S"));
cls_BRepTools.def_static("Update_", (void (*)(const TopoDS_CompSolid &)) &BRepTools::Update, "Update a composite solid (nothing is done)", py::arg("C"));
cls_BRepTools.def_static("Update_", (void (*)(const TopoDS_Compound &)) &BRepTools::Update, "Update a compound (nothing is done)", py::arg("C"));
cls_BRepTools.def_static("Update_", (void (*)(const TopoDS_Shape &)) &BRepTools::Update, "Update a shape, call the corect update.", py::arg("S"));
cls_BRepTools.def_static("UpdateFaceUVPoints_", (void (*)(const TopoDS_Face &)) &BRepTools::UpdateFaceUVPoints, "For each edge of the face <F> reset the UV points to the bounding points of the parametric curve of the edge on the face.", py::arg("theF"));
cls_BRepTools.def_static("Clean_", (void (*)(const TopoDS_Shape &)) &BRepTools::Clean, "Removes all the triangulations of the faces of <S> and removes all polygons on triangulations of the edges.", py::arg("S"));
cls_BRepTools.def_static("RemoveUnusedPCurves_", (void (*)(const TopoDS_Shape &)) &BRepTools::RemoveUnusedPCurves, "Removes all the pcurves of the edges of <S> that refer to surfaces not belonging to any face of <S>", py::arg("S"));
cls_BRepTools.def_static("Triangulation_", (Standard_Boolean (*)(const TopoDS_Shape &, const Standard_Real)) &BRepTools::Triangulation, "verifies that each face from the shape <S> has got a triangulation with a deflection <= deflec and the edges a discretisation on this triangulation.", py::arg("S"), py::arg("deflec"));
cls_BRepTools.def_static("Compare_", (Standard_Boolean (*)(const TopoDS_Vertex &, const TopoDS_Vertex &)) &BRepTools::Compare, "Returns True if the distance between the two vertices is lower than their tolerance.", py::arg("V1"), py::arg("V2"));
cls_BRepTools.def_static("Compare_", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Edge &)) &BRepTools::Compare, "Returns True if the distance between the two edges is lower than their tolerance.", py::arg("E1"), py::arg("E2"));
cls_BRepTools.def_static("OuterWire_", (TopoDS_Wire (*)(const TopoDS_Face &)) &BRepTools::OuterWire, "Returns the outer most wire of <F>. Returns a Null wire if <F> has no wires.", py::arg("F"));
cls_BRepTools.def_static("Map3DEdges_", (void (*)(const TopoDS_Shape &, TopTools_IndexedMapOfShape &)) &BRepTools::Map3DEdges, "Stores in the map <M> all the 3D topology edges of <S>.", py::arg("S"), py::arg("M"));
cls_BRepTools.def_static("IsReallyClosed_", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Face &)) &BRepTools::IsReallyClosed, "Verifies that the edge <E> is found two times on the face <F> before calling BRep_Tool::IsClosed.", py::arg("E"), py::arg("F"));
cls_BRepTools.def_static("DetectClosedness_", [](const TopoDS_Face & theFace, Standard_Boolean & theUclosed, Standard_Boolean & theVclosed){ BRepTools::DetectClosedness(theFace, theUclosed, theVclosed); return std::tuple<Standard_Boolean &, Standard_Boolean &>(theUclosed, theVclosed); }, "Detect closedness of face in U and V directions", py::arg("theFace"), py::arg("theUclosed"), py::arg("theVclosed"));
cls_BRepTools.def_static("Dump_", (void (*)(const TopoDS_Shape &, Standard_OStream &)) &BRepTools::Dump, "Dumps the topological structure and the geometry of <Sh> on the stream <S>.", py::arg("Sh"), py::arg("S"));
cls_BRepTools.def_static("Write_", [](const TopoDS_Shape & a0, Standard_OStream & a1) -> void { return BRepTools::Write(a0, a1); });
cls_BRepTools.def_static("Write_", (void (*)(const TopoDS_Shape &, Standard_OStream &, const opencascade::handle<Message_ProgressIndicator> &)) &BRepTools::Write, "Writes <Sh> on <S> in an ASCII format.", py::arg("Sh"), py::arg("S"), py::arg("PR"));
cls_BRepTools.def_static("Read_", [](TopoDS_Shape & a0, Standard_IStream & a1, const BRep_Builder & a2) -> void { return BRepTools::Read(a0, a1, a2); });
cls_BRepTools.def_static("Read_", (void (*)(TopoDS_Shape &, Standard_IStream &, const BRep_Builder &, const opencascade::handle<Message_ProgressIndicator> &)) &BRepTools::Read, "Reads a Shape from <S> in returns it in <Sh>. <B> is used to build the shape.", py::arg("Sh"), py::arg("S"), py::arg("B"), py::arg("PR"));
cls_BRepTools.def_static("Write_", [](const TopoDS_Shape & a0, const Standard_CString a1) -> Standard_Boolean { return BRepTools::Write(a0, a1); });
cls_BRepTools.def_static("Write_", (Standard_Boolean (*)(const TopoDS_Shape &, const Standard_CString, const opencascade::handle<Message_ProgressIndicator> &)) &BRepTools::Write, "Writes <Sh> in <File>.", py::arg("Sh"), py::arg("File"), py::arg("PR"));
cls_BRepTools.def_static("Read_", [](TopoDS_Shape & a0, const Standard_CString a1, const BRep_Builder & a2) -> Standard_Boolean { return BRepTools::Read(a0, a1, a2); });
cls_BRepTools.def_static("Read_", (Standard_Boolean (*)(TopoDS_Shape &, const Standard_CString, const BRep_Builder &, const opencascade::handle<Message_ProgressIndicator> &)) &BRepTools::Read, "Reads a Shape from <File>, returns it in <Sh>. <B> is used to build the shape.", py::arg("Sh"), py::arg("File"), py::arg("B"), py::arg("PR"));
cls_BRepTools.def_static("EvalAndUpdateTol_", (Standard_Real (*)(const TopoDS_Edge &, const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom2d_Curve>, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real)) &BRepTools::EvalAndUpdateTol, "Evals real tolerance of edge <theE>. <theC3d>, <theC2d>, <theS>, <theF>, <theL> are correspondently 3d curve of edge, 2d curve on surface <theS> and rang of edge If calculated tolerance is more then current edge tolerance, edge is updated. Method returns actual tolerance of edge", py::arg("theE"), py::arg("theC3d"), py::arg("theC2d"), py::arg("theS"), py::arg("theF"), py::arg("theL"));

// Enums

}