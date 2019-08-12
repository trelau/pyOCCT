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
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Handle.hxx>
#include <Message_ProgressIndicator.hxx>
#include <BRepTools_ReShape.hxx>
#include <TopoDS_Edge.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopoDS_Face.hxx>
#include <BRepBuilderAPI_Sewing.hxx>
#include <Standard_Type.hxx>
#include <TopTools_SequenceOfShape.hxx>
#include <TColStd_IndexedMapOfInteger.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <TColStd_SequenceOfBoolean.hxx>
#include <Geom_Surface.hxx>
#include <TopLoc_Location.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TColStd_Array1OfBoolean.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Geom2d_Curve.hxx>
#include <TopTools_MapOfShape.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <Geom_Curve.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <TopTools_IndexedDataMapOfShapeShape.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>

void bind_BRepBuilderAPI_Sewing(py::module &mod){

py::class_<BRepBuilderAPI_Sewing, opencascade::handle<BRepBuilderAPI_Sewing>, Standard_Transient> cls_BRepBuilderAPI_Sewing(mod, "BRepBuilderAPI_Sewing", "Provides methods to");

// Constructors
cls_BRepBuilderAPI_Sewing.def(py::init<>());
cls_BRepBuilderAPI_Sewing.def(py::init<const Standard_Real>(), py::arg("tolerance"));
cls_BRepBuilderAPI_Sewing.def(py::init<const Standard_Real, const Standard_Boolean>(), py::arg("tolerance"), py::arg("option1"));
cls_BRepBuilderAPI_Sewing.def(py::init<const Standard_Real, const Standard_Boolean, const Standard_Boolean>(), py::arg("tolerance"), py::arg("option1"), py::arg("option2"));
cls_BRepBuilderAPI_Sewing.def(py::init<const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("tolerance"), py::arg("option1"), py::arg("option2"), py::arg("option3"));
cls_BRepBuilderAPI_Sewing.def(py::init<const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("tolerance"), py::arg("option1"), py::arg("option2"), py::arg("option3"), py::arg("option4"));

// Fields

// Methods
cls_BRepBuilderAPI_Sewing.def("Init", [](BRepBuilderAPI_Sewing &self) -> void { return self.Init(); });
cls_BRepBuilderAPI_Sewing.def("Init", [](BRepBuilderAPI_Sewing &self, const Standard_Real a0) -> void { return self.Init(a0); });
cls_BRepBuilderAPI_Sewing.def("Init", [](BRepBuilderAPI_Sewing &self, const Standard_Real a0, const Standard_Boolean a1) -> void { return self.Init(a0, a1); });
cls_BRepBuilderAPI_Sewing.def("Init", [](BRepBuilderAPI_Sewing &self, const Standard_Real a0, const Standard_Boolean a1, const Standard_Boolean a2) -> void { return self.Init(a0, a1, a2); });
cls_BRepBuilderAPI_Sewing.def("Init", [](BRepBuilderAPI_Sewing &self, const Standard_Real a0, const Standard_Boolean a1, const Standard_Boolean a2, const Standard_Boolean a3) -> void { return self.Init(a0, a1, a2, a3); });
cls_BRepBuilderAPI_Sewing.def("Init", (void (BRepBuilderAPI_Sewing::*)(const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &BRepBuilderAPI_Sewing::Init, "initialize the parameters if necessary", py::arg("tolerance"), py::arg("option1"), py::arg("option2"), py::arg("option3"), py::arg("option4"));
cls_BRepBuilderAPI_Sewing.def("Load", (void (BRepBuilderAPI_Sewing::*)(const TopoDS_Shape &)) &BRepBuilderAPI_Sewing::Load, "Loades the context shape.", py::arg("shape"));
cls_BRepBuilderAPI_Sewing.def("Add", (void (BRepBuilderAPI_Sewing::*)(const TopoDS_Shape &)) &BRepBuilderAPI_Sewing::Add, "Defines the shapes to be sewed or controlled", py::arg("shape"));
cls_BRepBuilderAPI_Sewing.def("Perform", [](BRepBuilderAPI_Sewing &self) -> void { return self.Perform(); });
cls_BRepBuilderAPI_Sewing.def("Perform", (void (BRepBuilderAPI_Sewing::*)(const opencascade::handle<Message_ProgressIndicator> &)) &BRepBuilderAPI_Sewing::Perform, "Computing thePI - progress indicator of algorithm", py::arg("thePI"));
cls_BRepBuilderAPI_Sewing.def("SewedShape", (const TopoDS_Shape & (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::SewedShape, "Gives the sewed shape a null shape if nothing constructed may be a face, a shell, a solid or a compound");
cls_BRepBuilderAPI_Sewing.def("SetContext", (void (BRepBuilderAPI_Sewing::*)(const opencascade::handle<BRepTools_ReShape> &)) &BRepBuilderAPI_Sewing::SetContext, "set context", py::arg("theContext"));
cls_BRepBuilderAPI_Sewing.def("GetContext", (const opencascade::handle<BRepTools_ReShape> & (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::GetContext, "return context");
cls_BRepBuilderAPI_Sewing.def("NbFreeEdges", (Standard_Integer (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::NbFreeEdges, "Gives the number of free edges (edge shared by one face)");
cls_BRepBuilderAPI_Sewing.def("FreeEdge", (const TopoDS_Edge & (BRepBuilderAPI_Sewing::*)(const Standard_Integer) const) &BRepBuilderAPI_Sewing::FreeEdge, "Gives each free edge", py::arg("index"));
cls_BRepBuilderAPI_Sewing.def("NbMultipleEdges", (Standard_Integer (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::NbMultipleEdges, "Gives the number of multiple edges (edge shared by more than two faces)");
cls_BRepBuilderAPI_Sewing.def("MultipleEdge", (const TopoDS_Edge & (BRepBuilderAPI_Sewing::*)(const Standard_Integer) const) &BRepBuilderAPI_Sewing::MultipleEdge, "Gives each multiple edge", py::arg("index"));
cls_BRepBuilderAPI_Sewing.def("NbContigousEdges", (Standard_Integer (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::NbContigousEdges, "Gives the number of contigous edges (edge shared by two faces)");
cls_BRepBuilderAPI_Sewing.def("ContigousEdge", (const TopoDS_Edge & (BRepBuilderAPI_Sewing::*)(const Standard_Integer) const) &BRepBuilderAPI_Sewing::ContigousEdge, "Gives each contigous edge", py::arg("index"));
cls_BRepBuilderAPI_Sewing.def("ContigousEdgeCouple", (const TopTools_ListOfShape & (BRepBuilderAPI_Sewing::*)(const Standard_Integer) const) &BRepBuilderAPI_Sewing::ContigousEdgeCouple, "Gives the sections (edge) belonging to a contigous edge", py::arg("index"));
cls_BRepBuilderAPI_Sewing.def("IsSectionBound", (Standard_Boolean (BRepBuilderAPI_Sewing::*)(const TopoDS_Edge &) const) &BRepBuilderAPI_Sewing::IsSectionBound, "Indicates if a section is bound (before use SectionToBoundary)", py::arg("section"));
cls_BRepBuilderAPI_Sewing.def("SectionToBoundary", (const TopoDS_Edge & (BRepBuilderAPI_Sewing::*)(const TopoDS_Edge &) const) &BRepBuilderAPI_Sewing::SectionToBoundary, "Gives the original edge (free boundary) which becomes the the section. Remember that sections constitute common edges. This imformation is important for control because with original edge we can find the surface to which the section is attached.", py::arg("section"));
cls_BRepBuilderAPI_Sewing.def("NbDegeneratedShapes", (Standard_Integer (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::NbDegeneratedShapes, "Gives the number of degenerated shapes");
cls_BRepBuilderAPI_Sewing.def("DegeneratedShape", (const TopoDS_Shape & (BRepBuilderAPI_Sewing::*)(const Standard_Integer) const) &BRepBuilderAPI_Sewing::DegeneratedShape, "Gives each degenerated shape", py::arg("index"));
cls_BRepBuilderAPI_Sewing.def("IsDegenerated", (Standard_Boolean (BRepBuilderAPI_Sewing::*)(const TopoDS_Shape &) const) &BRepBuilderAPI_Sewing::IsDegenerated, "Indicates if a input shape is degenerated", py::arg("shape"));
cls_BRepBuilderAPI_Sewing.def("IsModified", (Standard_Boolean (BRepBuilderAPI_Sewing::*)(const TopoDS_Shape &) const) &BRepBuilderAPI_Sewing::IsModified, "Indicates if a input shape has been modified", py::arg("shape"));
cls_BRepBuilderAPI_Sewing.def("Modified", (const TopoDS_Shape & (BRepBuilderAPI_Sewing::*)(const TopoDS_Shape &) const) &BRepBuilderAPI_Sewing::Modified, "Gives a modifieded shape", py::arg("shape"));
cls_BRepBuilderAPI_Sewing.def("IsModifiedSubShape", (Standard_Boolean (BRepBuilderAPI_Sewing::*)(const TopoDS_Shape &) const) &BRepBuilderAPI_Sewing::IsModifiedSubShape, "Indicates if a input subshape has been modified", py::arg("shape"));
cls_BRepBuilderAPI_Sewing.def("ModifiedSubShape", (TopoDS_Shape (BRepBuilderAPI_Sewing::*)(const TopoDS_Shape &) const) &BRepBuilderAPI_Sewing::ModifiedSubShape, "Gives a modifieded subshape", py::arg("shape"));
cls_BRepBuilderAPI_Sewing.def("Dump", (void (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::Dump, "print the informations");
cls_BRepBuilderAPI_Sewing.def("NbDeletedFaces", (Standard_Integer (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::NbDeletedFaces, "Gives the number of deleted faces (faces smallest than tolerance)");
cls_BRepBuilderAPI_Sewing.def("DeletedFace", (const TopoDS_Face & (BRepBuilderAPI_Sewing::*)(const Standard_Integer) const) &BRepBuilderAPI_Sewing::DeletedFace, "Gives each deleted face", py::arg("index"));
cls_BRepBuilderAPI_Sewing.def("WhichFace", [](BRepBuilderAPI_Sewing &self, const TopoDS_Edge & a0) -> TopoDS_Face { return self.WhichFace(a0); });
cls_BRepBuilderAPI_Sewing.def("WhichFace", (TopoDS_Face (BRepBuilderAPI_Sewing::*)(const TopoDS_Edge &, const Standard_Integer) const) &BRepBuilderAPI_Sewing::WhichFace, "Gives a modified shape", py::arg("theEdg"), py::arg("index"));
cls_BRepBuilderAPI_Sewing.def("SameParameterMode", (Standard_Boolean (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::SameParameterMode, "Gets same parameter mode.");
cls_BRepBuilderAPI_Sewing.def("SetSameParameterMode", (void (BRepBuilderAPI_Sewing::*)(const Standard_Boolean)) &BRepBuilderAPI_Sewing::SetSameParameterMode, "Sets same parameter mode.", py::arg("SameParameterMode"));
cls_BRepBuilderAPI_Sewing.def("Tolerance", (Standard_Real (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::Tolerance, "Gives set tolerance.");
cls_BRepBuilderAPI_Sewing.def("SetTolerance", (void (BRepBuilderAPI_Sewing::*)(const Standard_Real)) &BRepBuilderAPI_Sewing::SetTolerance, "Sets tolerance", py::arg("theToler"));
cls_BRepBuilderAPI_Sewing.def("MinTolerance", (Standard_Real (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::MinTolerance, "Gives set min tolerance.");
cls_BRepBuilderAPI_Sewing.def("SetMinTolerance", (void (BRepBuilderAPI_Sewing::*)(const Standard_Real)) &BRepBuilderAPI_Sewing::SetMinTolerance, "Sets min tolerance", py::arg("theMinToler"));
cls_BRepBuilderAPI_Sewing.def("MaxTolerance", (Standard_Real (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::MaxTolerance, "Gives set max tolerance");
cls_BRepBuilderAPI_Sewing.def("SetMaxTolerance", (void (BRepBuilderAPI_Sewing::*)(const Standard_Real)) &BRepBuilderAPI_Sewing::SetMaxTolerance, "Sets max tolerance.", py::arg("theMaxToler"));
cls_BRepBuilderAPI_Sewing.def("FaceMode", (Standard_Boolean (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::FaceMode, "Returns mode for sewing faces By default - true.");
cls_BRepBuilderAPI_Sewing.def("SetFaceMode", (void (BRepBuilderAPI_Sewing::*)(const Standard_Boolean)) &BRepBuilderAPI_Sewing::SetFaceMode, "Sets mode for sewing faces By default - true.", py::arg("theFaceMode"));
cls_BRepBuilderAPI_Sewing.def("FloatingEdgesMode", (Standard_Boolean (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::FloatingEdgesMode, "Returns mode for sewing floating edges By default - false.");
cls_BRepBuilderAPI_Sewing.def("SetFloatingEdgesMode", (void (BRepBuilderAPI_Sewing::*)(const Standard_Boolean)) &BRepBuilderAPI_Sewing::SetFloatingEdgesMode, "Sets mode for sewing floating edges By default - false. Returns mode for cutting floating edges By default - false. Sets mode for cutting floating edges By default - false.", py::arg("theFloatingEdgesMode"));
cls_BRepBuilderAPI_Sewing.def("LocalTolerancesMode", (Standard_Boolean (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::LocalTolerancesMode, "Returns mode for accounting of local tolerances of edges and vertices during of merging.");
cls_BRepBuilderAPI_Sewing.def("SetLocalTolerancesMode", (void (BRepBuilderAPI_Sewing::*)(const Standard_Boolean)) &BRepBuilderAPI_Sewing::SetLocalTolerancesMode, "Sets mode for accounting of local tolerances of edges and vertices during of merging in this case WorkTolerance = myTolerance + tolEdge1+ tolEdg2;", py::arg("theLocalTolerancesMode"));
cls_BRepBuilderAPI_Sewing.def("SetNonManifoldMode", (void (BRepBuilderAPI_Sewing::*)(const Standard_Boolean)) &BRepBuilderAPI_Sewing::SetNonManifoldMode, "Sets mode for non-manifold sewing.", py::arg("theNonManifoldMode"));
cls_BRepBuilderAPI_Sewing.def("NonManifoldMode", (Standard_Boolean (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::NonManifoldMode, "Gets mode for non-manifold sewing.");
cls_BRepBuilderAPI_Sewing.def_static("get_type_name_", (const char * (*)()) &BRepBuilderAPI_Sewing::get_type_name, "None");
cls_BRepBuilderAPI_Sewing.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepBuilderAPI_Sewing::get_type_descriptor, "None");
cls_BRepBuilderAPI_Sewing.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::DynamicType, "None");

// Enums

}