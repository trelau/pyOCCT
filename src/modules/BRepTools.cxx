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
#include <TopTools_ListOfShape.hxx>
#include <BRepTools_History.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <Standard_Handle.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Std.hxx>
#include <Standard_Type.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <TopTools_MapOfShape.hxx>
#include <Standard.hxx>
#include <BRepTools_Modification.hxx>
#include <Message_ProgressIndicator.hxx>
#include <Geom_Curve.hxx>
#include <TopLoc_Location.hxx>
#include <Geom_Surface.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <NCollection_DataMap.hxx>
#include <TopoDS_Edge.hxx>
#include <BRepTools_Modifier.hxx>
#include <TopTools_ShapeMapHasher.hxx>
#include <TopoDS_Face.hxx>
#include <BRepTools_ReShape.hxx>
#include <TopoDS_Vertex.hxx>
#include <gp_Pnt.hxx>
#include <TopoDS_Wire.hxx>
#include <TopAbs_Orientation.hxx>
#include <BRepTools_WireExplorer.hxx>
#include <Poly_Triangulation.hxx>
#include <Poly_Polygon3D.hxx>
#include <Poly_PolygonOnTriangulation.hxx>
#include <Geom2d_Curve.hxx>
#include <GeomAbs_Shape.hxx>
#include <Bnd_Box2d.hxx>
#include <TopoDS_Shell.hxx>
#include <TopoDS_Solid.hxx>
#include <TopoDS_CompSolid.hxx>
#include <TopoDS_Compound.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <Standard_IStream.hxx>
#include <BRep_Builder.hxx>
#include <BRepTools_TrsfModification.hxx>
#include <BRepTools_NurbsConvertModification.hxx>
#include <BRepTools_GTrsfModification.hxx>
#include <BRepTools_Substitution.hxx>
#include <BRepTools_Quilt.hxx>
#include <BRepTools_ShapeSet.hxx>
#include <BRepTools.hxx>
#include <TColgp_SequenceOfPnt2d.hxx>
#include <BRepTools_MapOfVertexPnt2d.hxx>
#include <gp_GTrsf.hxx>
#include <TColStd_ListOfTransient.hxx>
#include <TColStd_IndexedDataMapOfTransientTransient.hxx>
#include <TopTools_IndexedDataMapOfShapeShape.hxx>
#include <TopTools_ShapeSet.hxx>
#include <GeomTools_SurfaceSet.hxx>
#include <GeomTools_CurveSet.hxx>
#include <GeomTools_Curve2dSet.hxx>
#include <TColStd_IndexedMapOfTransient.hxx>
#include <gp_Trsf.hxx>
#include <bind_NCollection_DataMap.hxx>

PYBIND11_MODULE(BRepTools, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.Message");
py::module::import("OCCT.Geom");
py::module::import("OCCT.TopLoc");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.gp");
py::module::import("OCCT.Poly");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.BRep");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.GeomTools");

// CLASS: BREPTOOLS_HISTORY
py::class_<BRepTools_History, opencascade::handle<BRepTools_History>, Standard_Transient> cls_BRepTools_History(mod, "BRepTools_History", "The history keeps the following relations between the input shapes (S1, ..., Sm) and output shapes (T1, ..., Tn): 1) an output shape Tj is generated from an input shape Si: Tj <= G(Si); 2) a output shape Tj is modified from an input shape Si: Tj <= M(Si); 3) an input shape (Si) is removed: R(Si) == 1.");

// Constructors
cls_BRepTools_History.def(py::init<>());

// Methods
cls_BRepTools_History.def_static("IsSupportedType_", (Standard_Boolean (*)(const TopoDS_Shape &)) &BRepTools_History::IsSupportedType, "Returns 'true' if the type of the shape is supported by the history.", py::arg("theShape"));
cls_BRepTools_History.def("AddGenerated", (void (BRepTools_History::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepTools_History::AddGenerated, "Set the second shape as generated one from the first shape.", py::arg("theInitial"), py::arg("theGenerated"));
cls_BRepTools_History.def("AddModified", (void (BRepTools_History::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepTools_History::AddModified, "Set the second shape as modified one from the first shape.", py::arg("theInitial"), py::arg("theModified"));
cls_BRepTools_History.def("Remove", (void (BRepTools_History::*)(const TopoDS_Shape &)) &BRepTools_History::Remove, "Set the shape as removed one.", py::arg("theRemoved"));
cls_BRepTools_History.def("ReplaceGenerated", (void (BRepTools_History::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepTools_History::ReplaceGenerated, "Set the second shape as the only generated one from the first one.", py::arg("theInitial"), py::arg("theGenerated"));
cls_BRepTools_History.def("ReplaceModified", (void (BRepTools_History::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepTools_History::ReplaceModified, "Set the second shape as the only modified one from the first one.", py::arg("theInitial"), py::arg("theModified"));
cls_BRepTools_History.def("Clear", (void (BRepTools_History::*)()) &BRepTools_History::Clear, "Clears the history.");
cls_BRepTools_History.def("Generated", (const TopTools_ListOfShape & (BRepTools_History::*)(const TopoDS_Shape &) const) &BRepTools_History::Generated, "Returns all shapes generated from the shape.", py::arg("theInitial"));
cls_BRepTools_History.def("Modified", (const TopTools_ListOfShape & (BRepTools_History::*)(const TopoDS_Shape &) const) &BRepTools_History::Modified, "Returns all shapes modified from the shape.", py::arg("theInitial"));
cls_BRepTools_History.def("IsRemoved", (Standard_Boolean (BRepTools_History::*)(const TopoDS_Shape &) const) &BRepTools_History::IsRemoved, "Returns 'true' if the shape is removed.", py::arg("theInitial"));
cls_BRepTools_History.def("HasGenerated", (Standard_Boolean (BRepTools_History::*)() const) &BRepTools_History::HasGenerated, "Returns 'true' if there any shapes with Generated elements present");
cls_BRepTools_History.def("HasModified", (Standard_Boolean (BRepTools_History::*)() const) &BRepTools_History::HasModified, "Returns 'true' if there any Modified shapes present");
cls_BRepTools_History.def("HasRemoved", (Standard_Boolean (BRepTools_History::*)() const) &BRepTools_History::HasRemoved, "Returns 'true' if there any removed shapes present");
cls_BRepTools_History.def("Merge", (void (BRepTools_History::*)(const opencascade::handle<BRepTools_History> &)) &BRepTools_History::Merge, "Merges the next history to this history.", py::arg("theHistory23"));
cls_BRepTools_History.def("Merge", (void (BRepTools_History::*)(const BRepTools_History &)) &BRepTools_History::Merge, "Merges the next history to this history.", py::arg("theHistory23"));
cls_BRepTools_History.def("Dump", (void (BRepTools_History::*)(Standard_OStream &)) &BRepTools_History::Dump, "Prints the brief description of the history into a stream", py::arg("theS"));
cls_BRepTools_History.def_static("get_type_name_", (const char * (*)()) &BRepTools_History::get_type_name, "None");
cls_BRepTools_History.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepTools_History::get_type_descriptor, "None");
cls_BRepTools_History.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepTools_History::*)() const) &BRepTools_History::DynamicType, "None");

// Enums
py::enum_<BRepTools_History::TRelationType>(cls_BRepTools_History, "TRelationType", "The types of the historical relations.")
	.value("TRelationType_Removed", BRepTools_History::TRelationType::TRelationType_Removed)
	.value("TRelationType_Generated", BRepTools_History::TRelationType::TRelationType_Generated)
	.value("TRelationType_Modified", BRepTools_History::TRelationType::TRelationType_Modified)
	.export_values();

// CLASS: BREPTOOLS_MODIFIER
py::class_<BRepTools_Modifier> cls_BRepTools_Modifier(mod, "BRepTools_Modifier", "Performs geometric modifications on a shape.");

// Constructors
cls_BRepTools_Modifier.def(py::init<>());
cls_BRepTools_Modifier.def(py::init<Standard_Boolean>(), py::arg("theMutableInput"));
cls_BRepTools_Modifier.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
cls_BRepTools_Modifier.def(py::init<const TopoDS_Shape &, const opencascade::handle<BRepTools_Modification> &>(), py::arg("S"), py::arg("M"));

// Methods
// cls_BRepTools_Modifier.def_static("operator new_", (void * (*)(size_t)) &BRepTools_Modifier::operator new, "None", py::arg("theSize"));
// cls_BRepTools_Modifier.def_static("operator delete_", (void (*)(void *)) &BRepTools_Modifier::operator delete, "None", py::arg("theAddress"));
// cls_BRepTools_Modifier.def_static("operator new[]_", (void * (*)(size_t)) &BRepTools_Modifier::operator new[], "None", py::arg("theSize"));
// cls_BRepTools_Modifier.def_static("operator delete[]_", (void (*)(void *)) &BRepTools_Modifier::operator delete[], "None", py::arg("theAddress"));
// cls_BRepTools_Modifier.def_static("operator new_", (void * (*)(size_t, void *)) &BRepTools_Modifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepTools_Modifier.def_static("operator delete_", (void (*)(void *, void *)) &BRepTools_Modifier::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepTools_Modifier.def("Init", (void (BRepTools_Modifier::*)(const TopoDS_Shape &)) &BRepTools_Modifier::Init, "Initializes the modifier with the shape <S>.", py::arg("S"));
cls_BRepTools_Modifier.def("Perform", [](BRepTools_Modifier &self, const opencascade::handle<BRepTools_Modification> & a0) -> void { return self.Perform(a0); });
cls_BRepTools_Modifier.def("Perform", (void (BRepTools_Modifier::*)(const opencascade::handle<BRepTools_Modification> &, const opencascade::handle<Message_ProgressIndicator> &)) &BRepTools_Modifier::Perform, "Performs the modifications described by <M>.", py::arg("M"), py::arg("aProgress"));
cls_BRepTools_Modifier.def("IsDone", (Standard_Boolean (BRepTools_Modifier::*)() const) &BRepTools_Modifier::IsDone, "Returns Standard_True if the modification has been computed successfully.");
cls_BRepTools_Modifier.def("IsMutableInput", (Standard_Boolean (BRepTools_Modifier::*)() const) &BRepTools_Modifier::IsMutableInput, "Returns the current mutable input state");
cls_BRepTools_Modifier.def("SetMutableInput", (void (BRepTools_Modifier::*)(Standard_Boolean)) &BRepTools_Modifier::SetMutableInput, "Sets the mutable input state If true then the input (original) shape can be modified during modification process", py::arg("theMutableInput"));
cls_BRepTools_Modifier.def("ModifiedShape", (const TopoDS_Shape & (BRepTools_Modifier::*)(const TopoDS_Shape &) const) &BRepTools_Modifier::ModifiedShape, "Returns the modified shape corresponding to <S>.", py::arg("S"));

// CLASS: BREPTOOLS_RESHAPE
py::class_<BRepTools_ReShape, opencascade::handle<BRepTools_ReShape>, Standard_Transient> cls_BRepTools_ReShape(mod, "BRepTools_ReShape", "Rebuilds a Shape by making pre-defined substitutions on some of its components");

// Constructors
cls_BRepTools_ReShape.def(py::init<>());

// Methods
cls_BRepTools_ReShape.def("Clear", (void (BRepTools_ReShape::*)()) &BRepTools_ReShape::Clear, "Clears all substitutions requests");
cls_BRepTools_ReShape.def("Remove", (void (BRepTools_ReShape::*)(const TopoDS_Shape &)) &BRepTools_ReShape::Remove, "Sets a request to Remove a Shape whatever the orientation", py::arg("shape"));
cls_BRepTools_ReShape.def("Replace", (void (BRepTools_ReShape::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepTools_ReShape::Replace, "Sets a request to Replace a Shape by a new one.", py::arg("shape"), py::arg("newshape"));
cls_BRepTools_ReShape.def("IsRecorded", (Standard_Boolean (BRepTools_ReShape::*)(const TopoDS_Shape &) const) &BRepTools_ReShape::IsRecorded, "Tells if a shape is recorded for Replace/Remove", py::arg("shape"));
cls_BRepTools_ReShape.def("Value", (TopoDS_Shape (BRepTools_ReShape::*)(const TopoDS_Shape &) const) &BRepTools_ReShape::Value, "Returns the new value for an individual shape If not recorded, returns the original shape itself If to be Removed, returns a Null Shape Else, returns the replacing item", py::arg("shape"));
cls_BRepTools_ReShape.def("Status", [](BRepTools_ReShape &self, const TopoDS_Shape & a0, TopoDS_Shape & a1) -> Standard_Integer { return self.Status(a0, a1); });
cls_BRepTools_ReShape.def("Status", (Standard_Integer (BRepTools_ReShape::*)(const TopoDS_Shape &, TopoDS_Shape &, const Standard_Boolean)) &BRepTools_ReShape::Status, "Returns a complete substitution status for a shape 0 : not recorded, <newsh> = original <shape> < 0: to be removed, <newsh> is NULL > 0: to be replaced, <newsh> is a new item If <last> is False, returns status and new shape recorded in the map directly for the shape, if True and status > 0 then recursively searches for the last status and new shape.", py::arg("shape"), py::arg("newsh"), py::arg("last"));
cls_BRepTools_ReShape.def("Apply", [](BRepTools_ReShape &self, const TopoDS_Shape & a0) -> TopoDS_Shape { return self.Apply(a0); });
cls_BRepTools_ReShape.def("Apply", (TopoDS_Shape (BRepTools_ReShape::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum)) &BRepTools_ReShape::Apply, "Applies the substitutions requests to a shape.", py::arg("shape"), py::arg("until"));
cls_BRepTools_ReShape.def("ModeConsiderLocation", (Standard_Boolean & (BRepTools_ReShape::*)()) &BRepTools_ReShape::ModeConsiderLocation, "Returns (modifiable) the flag which defines whether Location of shape take into account during replacing shapes.");
cls_BRepTools_ReShape.def("CopyVertex", [](BRepTools_ReShape &self, const TopoDS_Vertex & a0) -> TopoDS_Vertex { return self.CopyVertex(a0); });
cls_BRepTools_ReShape.def("CopyVertex", (TopoDS_Vertex (BRepTools_ReShape::*)(const TopoDS_Vertex &, const Standard_Real)) &BRepTools_ReShape::CopyVertex, "None", py::arg("theV"), py::arg("theTol"));
cls_BRepTools_ReShape.def("CopyVertex", (TopoDS_Vertex (BRepTools_ReShape::*)(const TopoDS_Vertex &, const gp_Pnt &, const Standard_Real)) &BRepTools_ReShape::CopyVertex, "None", py::arg("theV"), py::arg("theNewPos"), py::arg("aTol"));
cls_BRepTools_ReShape.def("IsNewShape", (Standard_Boolean (BRepTools_ReShape::*)(const TopoDS_Shape &) const) &BRepTools_ReShape::IsNewShape, "None", py::arg("theShape"));
cls_BRepTools_ReShape.def("History", (opencascade::handle<BRepTools_History> (BRepTools_ReShape::*)() const) &BRepTools_ReShape::History, "Returns the history of the substituted shapes.");
cls_BRepTools_ReShape.def_static("get_type_name_", (const char * (*)()) &BRepTools_ReShape::get_type_name, "None");
cls_BRepTools_ReShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepTools_ReShape::get_type_descriptor, "None");
cls_BRepTools_ReShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepTools_ReShape::*)() const) &BRepTools_ReShape::DynamicType, "None");

// CLASS: BREPTOOLS_WIREEXPLORER
py::class_<BRepTools_WireExplorer> cls_BRepTools_WireExplorer(mod, "BRepTools_WireExplorer", "The WireExplorer is a tool to explore the edges of a wire in a connection order.");

// Constructors
cls_BRepTools_WireExplorer.def(py::init<>());
cls_BRepTools_WireExplorer.def(py::init<const TopoDS_Wire &>(), py::arg("W"));
cls_BRepTools_WireExplorer.def(py::init<const TopoDS_Wire &, const TopoDS_Face &>(), py::arg("W"), py::arg("F"));

// Methods
// cls_BRepTools_WireExplorer.def_static("operator new_", (void * (*)(size_t)) &BRepTools_WireExplorer::operator new, "None", py::arg("theSize"));
// cls_BRepTools_WireExplorer.def_static("operator delete_", (void (*)(void *)) &BRepTools_WireExplorer::operator delete, "None", py::arg("theAddress"));
// cls_BRepTools_WireExplorer.def_static("operator new[]_", (void * (*)(size_t)) &BRepTools_WireExplorer::operator new[], "None", py::arg("theSize"));
// cls_BRepTools_WireExplorer.def_static("operator delete[]_", (void (*)(void *)) &BRepTools_WireExplorer::operator delete[], "None", py::arg("theAddress"));
// cls_BRepTools_WireExplorer.def_static("operator new_", (void * (*)(size_t, void *)) &BRepTools_WireExplorer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepTools_WireExplorer.def_static("operator delete_", (void (*)(void *, void *)) &BRepTools_WireExplorer::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepTools_WireExplorer.def("Init", (void (BRepTools_WireExplorer::*)(const TopoDS_Wire &)) &BRepTools_WireExplorer::Init, "Initializes an exploration of the wire <W>.", py::arg("W"));
cls_BRepTools_WireExplorer.def("Init", (void (BRepTools_WireExplorer::*)(const TopoDS_Wire &, const TopoDS_Face &)) &BRepTools_WireExplorer::Init, "Initializes an exploration of the wire <W>. F is used to select the edge connected to the previous in the parametric representation of <F>.", py::arg("W"), py::arg("F"));
cls_BRepTools_WireExplorer.def("Init", (void (BRepTools_WireExplorer::*)(const TopoDS_Wire &, const TopoDS_Face &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &BRepTools_WireExplorer::Init, "Initializes an exploration of the wire <W>. F is used to select the edge connected to the previous in the parametric representation of <F>. <UMIn>, <UMax>, <VMin>, <VMax> - the UV bounds of the face <F>.", py::arg("W"), py::arg("F"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
cls_BRepTools_WireExplorer.def("More", (Standard_Boolean (BRepTools_WireExplorer::*)() const) &BRepTools_WireExplorer::More, "Returns True if there is a current edge.");
cls_BRepTools_WireExplorer.def("Next", (void (BRepTools_WireExplorer::*)()) &BRepTools_WireExplorer::Next, "Proceeds to the next edge.");
cls_BRepTools_WireExplorer.def("Current", (const TopoDS_Edge & (BRepTools_WireExplorer::*)() const) &BRepTools_WireExplorer::Current, "Returns the current edge.");
cls_BRepTools_WireExplorer.def("Orientation", (TopAbs_Orientation (BRepTools_WireExplorer::*)() const) &BRepTools_WireExplorer::Orientation, "Returns an Orientation for the current edge.");
cls_BRepTools_WireExplorer.def("CurrentVertex", (const TopoDS_Vertex & (BRepTools_WireExplorer::*)() const) &BRepTools_WireExplorer::CurrentVertex, "Returns the vertex connecting the current edge to the previous one.");
cls_BRepTools_WireExplorer.def("Clear", (void (BRepTools_WireExplorer::*)()) &BRepTools_WireExplorer::Clear, "Clears the content of the explorer.");

// CLASS: BREPTOOLS_MODIFICATION
py::class_<BRepTools_Modification, opencascade::handle<BRepTools_Modification>, Standard_Transient> cls_BRepTools_Modification(mod, "BRepTools_Modification", "Defines geometric modifications to a shape, i.e. changes to faces, edges and vertices.");

// Methods
cls_BRepTools_Modification.def("NewSurface", [](BRepTools_Modification &self, const TopoDS_Face & F, opencascade::handle<Geom_Surface> & S, TopLoc_Location & L, Standard_Real & Tol, Standard_Boolean & RevWires, Standard_Boolean & RevFace){ Standard_Boolean rv = self.NewSurface(F, S, L, Tol, RevWires, RevFace); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Boolean &, Standard_Boolean &>(rv, Tol, RevWires, RevFace); }, "Returns true if the face, F, has been modified. If the face has been modified: - S is the new geometry of the face, - L is its new location, and - Tol is the new tolerance. The flag, RevWires, is set to true when the modification reverses the normal of the surface, (i.e. the wires have to be reversed). The flag, RevFace, is set to true if the orientation of the modified face changes in the shells which contain it. If the face has not been modified this function returns false, and the values of S, L, Tol, RevWires and RevFace are not significant.", py::arg("F"), py::arg("S"), py::arg("L"), py::arg("Tol"), py::arg("RevWires"), py::arg("RevFace"));
cls_BRepTools_Modification.def("NewTriangulation", (Standard_Boolean (BRepTools_Modification::*)(const TopoDS_Face &, opencascade::handle<Poly_Triangulation> &)) &BRepTools_Modification::NewTriangulation, "Returns true if the face has been modified according to changed triangulation. If the face has been modified: - T is a new triangulation on the face", py::arg("F"), py::arg("T"));
cls_BRepTools_Modification.def("NewCurve", [](BRepTools_Modification &self, const TopoDS_Edge & E, opencascade::handle<Geom_Curve> & C, TopLoc_Location & L, Standard_Real & Tol){ Standard_Boolean rv = self.NewCurve(E, C, L, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "Returns true if the edge, E, has been modified. If the edge has been modified: - C is the new geometry associated with the edge, - L is its new location, and - Tol is the new tolerance. If the edge has not been modified, this function returns false, and the values of C, L and Tol are not significant.", py::arg("E"), py::arg("C"), py::arg("L"), py::arg("Tol"));
cls_BRepTools_Modification.def("NewPolygon", (Standard_Boolean (BRepTools_Modification::*)(const TopoDS_Edge &, opencascade::handle<Poly_Polygon3D> &)) &BRepTools_Modification::NewPolygon, "Returns true if the edge has been modified according to changed polygon. If the edge has been modified: - P is a new polygon", py::arg("E"), py::arg("P"));
cls_BRepTools_Modification.def("NewPolygonOnTriangulation", (Standard_Boolean (BRepTools_Modification::*)(const TopoDS_Edge &, const TopoDS_Face &, opencascade::handle<Poly_PolygonOnTriangulation> &)) &BRepTools_Modification::NewPolygonOnTriangulation, "Returns true if the edge has been modified according to changed polygon on triangulation. If the edge has been modified: - P is a new polygon on triangulation", py::arg("E"), py::arg("F"), py::arg("P"));
cls_BRepTools_Modification.def("NewPoint", [](BRepTools_Modification &self, const TopoDS_Vertex & V, gp_Pnt & P, Standard_Real & Tol){ Standard_Boolean rv = self.NewPoint(V, P, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "Returns true if the vertex V has been modified. If V has been modified: - P is the new geometry of the vertex, and - Tol is the new tolerance. If the vertex has not been modified this function returns false, and the values of P and Tol are not significant.", py::arg("V"), py::arg("P"), py::arg("Tol"));
cls_BRepTools_Modification.def("NewCurve2d", [](BRepTools_Modification &self, const TopoDS_Edge & E, const TopoDS_Face & F, const TopoDS_Edge & NewE, const TopoDS_Face & NewF, opencascade::handle<Geom2d_Curve> & C, Standard_Real & Tol){ Standard_Boolean rv = self.NewCurve2d(E, F, NewE, NewF, C, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "Returns true if the edge, E, has a new curve on surface on the face, F. If a new curve exists: - C is the new geometry of the edge, - L is the new location, and - Tol is the new tolerance. NewE is the new edge created from E, and NewF is the new face created from F. If there is no new curve on the face, this function returns false, and the values of C, L and Tol are not significant.", py::arg("E"), py::arg("F"), py::arg("NewE"), py::arg("NewF"), py::arg("C"), py::arg("Tol"));
cls_BRepTools_Modification.def("NewParameter", [](BRepTools_Modification &self, const TopoDS_Vertex & V, const TopoDS_Edge & E, Standard_Real & P, Standard_Real & Tol){ Standard_Boolean rv = self.NewParameter(V, E, P, Tol); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, P, Tol); }, "Returns true if the vertex V has a new parameter on the edge E. If a new parameter exists: - P is the parameter, and - Tol is the new tolerance. If there is no new parameter this function returns false, and the values of P and Tol are not significant.", py::arg("V"), py::arg("E"), py::arg("P"), py::arg("Tol"));
cls_BRepTools_Modification.def("Continuity", (GeomAbs_Shape (BRepTools_Modification::*)(const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &, const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &)) &BRepTools_Modification::Continuity, "Returns the continuity of <NewE> between <NewF1> and <NewF2>. <NewE> is the new edge created from <E>. <NewF1> (resp. <NewF2>) is the new face created from <F1> (resp. <F2>).", py::arg("E"), py::arg("F1"), py::arg("F2"), py::arg("NewE"), py::arg("NewF1"), py::arg("NewF2"));
cls_BRepTools_Modification.def_static("get_type_name_", (const char * (*)()) &BRepTools_Modification::get_type_name, "None");
cls_BRepTools_Modification.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepTools_Modification::get_type_descriptor, "None");
cls_BRepTools_Modification.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepTools_Modification::*)() const) &BRepTools_Modification::DynamicType, "None");

// CLASS: BREPTOOLS
py::class_<BRepTools> cls_BRepTools(mod, "BRepTools", "The BRepTools package provides utilities for BRep data structures.");

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
cls_BRepTools.def_static("CleanGeometry_", (void (*)(const TopoDS_Shape &)) &BRepTools::CleanGeometry, "Removes geometry (curves and surfaces) from all edges and faces of the shape", py::arg("theShape"));
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

// TYPEDEF: BREPTOOLS_MAPOFVERTEXPNT2D
bind_NCollection_DataMap<TopoDS_Shape, NCollection_Sequence<gp_Pnt2d>, TopTools_ShapeMapHasher>(mod, "BRepTools_MapOfVertexPnt2d", py::module_local(false));

// TYPEDEF: BREPTOOLS_DATAMAPITERATOROFMAPOFVERTEXPNT2D

// CLASS: BREPTOOLS_GTRSFMODIFICATION
py::class_<BRepTools_GTrsfModification, opencascade::handle<BRepTools_GTrsfModification>, BRepTools_Modification> cls_BRepTools_GTrsfModification(mod, "BRepTools_GTrsfModification", "Defines a modification of the geometry by a GTrsf from gp. All methods return True and transform the geometry.");

// Constructors
cls_BRepTools_GTrsfModification.def(py::init<const gp_GTrsf &>(), py::arg("T"));

// Methods
cls_BRepTools_GTrsfModification.def("GTrsf", (gp_GTrsf & (BRepTools_GTrsfModification::*)()) &BRepTools_GTrsfModification::GTrsf, "Gives an access on the GTrsf.");
cls_BRepTools_GTrsfModification.def("NewSurface", [](BRepTools_GTrsfModification &self, const TopoDS_Face & F, opencascade::handle<Geom_Surface> & S, TopLoc_Location & L, Standard_Real & Tol, Standard_Boolean & RevWires, Standard_Boolean & RevFace){ Standard_Boolean rv = self.NewSurface(F, S, L, Tol, RevWires, RevFace); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Boolean &, Standard_Boolean &>(rv, Tol, RevWires, RevFace); }, "Returns Standard_True if the face <F> has been modified. In this case, <S> is the new geometric support of the face, <L> the new location,<Tol> the new tolerance.<RevWires> has to be set to Standard_True when the modification reverses the normal of the surface.(the wires have to be reversed). <RevFace> has to be set to Standard_True if the orientation of the modified face changes in the shells which contain it. -- Here, <RevFace> will return Standard_True if the -- gp_Trsf is negative.", py::arg("F"), py::arg("S"), py::arg("L"), py::arg("Tol"), py::arg("RevWires"), py::arg("RevFace"));
cls_BRepTools_GTrsfModification.def("NewCurve", [](BRepTools_GTrsfModification &self, const TopoDS_Edge & E, opencascade::handle<Geom_Curve> & C, TopLoc_Location & L, Standard_Real & Tol){ Standard_Boolean rv = self.NewCurve(E, C, L, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "Returns Standard_True if the edge <E> has been modified. In this case, <C> is the new geometric support of the edge, <L> the new location, <Tol> the new tolerance. Otherwise, returns Standard_False, and <C>, <L>, <Tol> are not significant.", py::arg("E"), py::arg("C"), py::arg("L"), py::arg("Tol"));
cls_BRepTools_GTrsfModification.def("NewPoint", [](BRepTools_GTrsfModification &self, const TopoDS_Vertex & V, gp_Pnt & P, Standard_Real & Tol){ Standard_Boolean rv = self.NewPoint(V, P, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "Returns Standard_True if the vertex <V> has been modified. In this case, <P> is the new geometric support of the vertex, <Tol> the new tolerance. Otherwise, returns Standard_False, and <P>, <Tol> are not significant.", py::arg("V"), py::arg("P"), py::arg("Tol"));
cls_BRepTools_GTrsfModification.def("NewCurve2d", [](BRepTools_GTrsfModification &self, const TopoDS_Edge & E, const TopoDS_Face & F, const TopoDS_Edge & NewE, const TopoDS_Face & NewF, opencascade::handle<Geom2d_Curve> & C, Standard_Real & Tol){ Standard_Boolean rv = self.NewCurve2d(E, F, NewE, NewF, C, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "Returns Standard_True if the edge <E> has a new curve on surface on the face <F>.In this case, <C> is the new geometric support of the edge, <L> the new location, <Tol> the new tolerance. Otherwise, returns Standard_False, and <C>, <L>, <Tol> are not significant.", py::arg("E"), py::arg("F"), py::arg("NewE"), py::arg("NewF"), py::arg("C"), py::arg("Tol"));
cls_BRepTools_GTrsfModification.def("NewParameter", [](BRepTools_GTrsfModification &self, const TopoDS_Vertex & V, const TopoDS_Edge & E, Standard_Real & P, Standard_Real & Tol){ Standard_Boolean rv = self.NewParameter(V, E, P, Tol); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, P, Tol); }, "Returns Standard_True if the Vertex <V> has a new parameter on the edge <E>. In this case, <P> is the parameter, <Tol> the new tolerance. Otherwise, returns Standard_False, and <P>, <Tol> are not significant.", py::arg("V"), py::arg("E"), py::arg("P"), py::arg("Tol"));
cls_BRepTools_GTrsfModification.def("Continuity", (GeomAbs_Shape (BRepTools_GTrsfModification::*)(const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &, const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &)) &BRepTools_GTrsfModification::Continuity, "Returns the continuity of <NewE> between <NewF1> and <NewF2>.", py::arg("E"), py::arg("F1"), py::arg("F2"), py::arg("NewE"), py::arg("NewF1"), py::arg("NewF2"));
cls_BRepTools_GTrsfModification.def_static("get_type_name_", (const char * (*)()) &BRepTools_GTrsfModification::get_type_name, "None");
cls_BRepTools_GTrsfModification.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepTools_GTrsfModification::get_type_descriptor, "None");
cls_BRepTools_GTrsfModification.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepTools_GTrsfModification::*)() const) &BRepTools_GTrsfModification::DynamicType, "None");

// CLASS: BREPTOOLS_NURBSCONVERTMODIFICATION
py::class_<BRepTools_NurbsConvertModification, opencascade::handle<BRepTools_NurbsConvertModification>, BRepTools_Modification> cls_BRepTools_NurbsConvertModification(mod, "BRepTools_NurbsConvertModification", "Defines a modification of the geometry by a Trsf from gp. All methods return True and transform the geometry.");

// Constructors
cls_BRepTools_NurbsConvertModification.def(py::init<>());

// Methods
cls_BRepTools_NurbsConvertModification.def("NewSurface", [](BRepTools_NurbsConvertModification &self, const TopoDS_Face & F, opencascade::handle<Geom_Surface> & S, TopLoc_Location & L, Standard_Real & Tol, Standard_Boolean & RevWires, Standard_Boolean & RevFace){ Standard_Boolean rv = self.NewSurface(F, S, L, Tol, RevWires, RevFace); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Boolean &, Standard_Boolean &>(rv, Tol, RevWires, RevFace); }, "Returns Standard_True if the face <F> has been modified. In this case, <S> is the new geometric support of the face, <L> the new location,<Tol> the new tolerance.<RevWires> has to be set to Standard_True when the modification reverses the normal of the surface.(the wires have to be reversed). <RevFace> has to be set to Standard_True if the orientation of the modified face changes in the shells which contain it. -- Here, <RevFace> will return Standard_True if the -- gp_Trsf is negative.", py::arg("F"), py::arg("S"), py::arg("L"), py::arg("Tol"), py::arg("RevWires"), py::arg("RevFace"));
cls_BRepTools_NurbsConvertModification.def("NewCurve", [](BRepTools_NurbsConvertModification &self, const TopoDS_Edge & E, opencascade::handle<Geom_Curve> & C, TopLoc_Location & L, Standard_Real & Tol){ Standard_Boolean rv = self.NewCurve(E, C, L, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "Returns Standard_True if the edge <E> has been modified. In this case, <C> is the new geometric support of the edge, <L> the new location, <Tol> the new tolerance. Otherwise, returns Standard_False, and <C>, <L>, <Tol> are not significant.", py::arg("E"), py::arg("C"), py::arg("L"), py::arg("Tol"));
cls_BRepTools_NurbsConvertModification.def("NewPoint", [](BRepTools_NurbsConvertModification &self, const TopoDS_Vertex & V, gp_Pnt & P, Standard_Real & Tol){ Standard_Boolean rv = self.NewPoint(V, P, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "Returns Standard_True if the vertex <V> has been modified. In this case, <P> is the new geometric support of the vertex, <Tol> the new tolerance. Otherwise, returns Standard_False, and <P>, <Tol> are not significant.", py::arg("V"), py::arg("P"), py::arg("Tol"));
cls_BRepTools_NurbsConvertModification.def("NewCurve2d", [](BRepTools_NurbsConvertModification &self, const TopoDS_Edge & E, const TopoDS_Face & F, const TopoDS_Edge & NewE, const TopoDS_Face & NewF, opencascade::handle<Geom2d_Curve> & C, Standard_Real & Tol){ Standard_Boolean rv = self.NewCurve2d(E, F, NewE, NewF, C, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "Returns Standard_True if the edge <E> has a new curve on surface on the face <F>.In this case, <C> is the new geometric support of the edge, <L> the new location, <Tol> the new tolerance. Otherwise, returns Standard_False, and <C>, <L>, <Tol> are not significant.", py::arg("E"), py::arg("F"), py::arg("NewE"), py::arg("NewF"), py::arg("C"), py::arg("Tol"));
cls_BRepTools_NurbsConvertModification.def("NewParameter", [](BRepTools_NurbsConvertModification &self, const TopoDS_Vertex & V, const TopoDS_Edge & E, Standard_Real & P, Standard_Real & Tol){ Standard_Boolean rv = self.NewParameter(V, E, P, Tol); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, P, Tol); }, "Returns Standard_True if the Vertex <V> has a new parameter on the edge <E>. In this case, <P> is the parameter, <Tol> the new tolerance. Otherwise, returns Standard_False, and <P>, <Tol> are not significant.", py::arg("V"), py::arg("E"), py::arg("P"), py::arg("Tol"));
cls_BRepTools_NurbsConvertModification.def("Continuity", (GeomAbs_Shape (BRepTools_NurbsConvertModification::*)(const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &, const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &)) &BRepTools_NurbsConvertModification::Continuity, "Returns the continuity of <NewE> between <NewF1> and <NewF2>.", py::arg("E"), py::arg("F1"), py::arg("F2"), py::arg("NewE"), py::arg("NewF1"), py::arg("NewF2"));
cls_BRepTools_NurbsConvertModification.def("GetUpdatedEdges", (const TopTools_ListOfShape & (BRepTools_NurbsConvertModification::*)() const) &BRepTools_NurbsConvertModification::GetUpdatedEdges, "None");
cls_BRepTools_NurbsConvertModification.def_static("get_type_name_", (const char * (*)()) &BRepTools_NurbsConvertModification::get_type_name, "None");
cls_BRepTools_NurbsConvertModification.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepTools_NurbsConvertModification::get_type_descriptor, "None");
cls_BRepTools_NurbsConvertModification.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepTools_NurbsConvertModification::*)() const) &BRepTools_NurbsConvertModification::DynamicType, "None");

// CLASS: BREPTOOLS_QUILT
py::class_<BRepTools_Quilt> cls_BRepTools_Quilt(mod, "BRepTools_Quilt", "A Tool to glue faces at common edges and reconstruct shells.");

// Constructors
cls_BRepTools_Quilt.def(py::init<>());

// Methods
// cls_BRepTools_Quilt.def_static("operator new_", (void * (*)(size_t)) &BRepTools_Quilt::operator new, "None", py::arg("theSize"));
// cls_BRepTools_Quilt.def_static("operator delete_", (void (*)(void *)) &BRepTools_Quilt::operator delete, "None", py::arg("theAddress"));
// cls_BRepTools_Quilt.def_static("operator new[]_", (void * (*)(size_t)) &BRepTools_Quilt::operator new[], "None", py::arg("theSize"));
// cls_BRepTools_Quilt.def_static("operator delete[]_", (void (*)(void *)) &BRepTools_Quilt::operator delete[], "None", py::arg("theAddress"));
// cls_BRepTools_Quilt.def_static("operator new_", (void * (*)(size_t, void *)) &BRepTools_Quilt::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepTools_Quilt.def_static("operator delete_", (void (*)(void *, void *)) &BRepTools_Quilt::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepTools_Quilt.def("Bind", (void (BRepTools_Quilt::*)(const TopoDS_Edge &, const TopoDS_Edge &)) &BRepTools_Quilt::Bind, "Binds <Enew> to be the new edge instead of <Eold>.", py::arg("Eold"), py::arg("Enew"));
cls_BRepTools_Quilt.def("Bind", (void (BRepTools_Quilt::*)(const TopoDS_Vertex &, const TopoDS_Vertex &)) &BRepTools_Quilt::Bind, "Binds <VNew> to be a new vertex instead of <Vold>.", py::arg("Vold"), py::arg("Vnew"));
cls_BRepTools_Quilt.def("Add", (void (BRepTools_Quilt::*)(const TopoDS_Shape &)) &BRepTools_Quilt::Add, "Add the faces of <S> to the Quilt, the faces containing bounded edges are copied.", py::arg("S"));
cls_BRepTools_Quilt.def("IsCopied", (Standard_Boolean (BRepTools_Quilt::*)(const TopoDS_Shape &) const) &BRepTools_Quilt::IsCopied, "Returns True if <S> has been copied (<S> is a vertex, an edge or a face)", py::arg("S"));
cls_BRepTools_Quilt.def("Copy", (const TopoDS_Shape & (BRepTools_Quilt::*)(const TopoDS_Shape &) const) &BRepTools_Quilt::Copy, "Returns the shape substitued to <S> in the Quilt.", py::arg("S"));
cls_BRepTools_Quilt.def("Shells", (TopoDS_Shape (BRepTools_Quilt::*)() const) &BRepTools_Quilt::Shells, "Returns a Compound of shells made from the current set of faces. The shells will be flagged as closed or not closed.");

// CLASS: BREPTOOLS_SHAPESET
py::class_<BRepTools_ShapeSet, TopTools_ShapeSet> cls_BRepTools_ShapeSet(mod, "BRepTools_ShapeSet", "Contains a Shape and all its subshapes, locations and geometries.");

// Constructors
cls_BRepTools_ShapeSet.def(py::init<>());
cls_BRepTools_ShapeSet.def(py::init<const Standard_Boolean>(), py::arg("isWithTriangles"));
cls_BRepTools_ShapeSet.def(py::init<const BRep_Builder &>(), py::arg("B"));
cls_BRepTools_ShapeSet.def(py::init<const BRep_Builder &, const Standard_Boolean>(), py::arg("B"), py::arg("isWithTriangles"));

// Methods
// cls_BRepTools_ShapeSet.def_static("operator new_", (void * (*)(size_t)) &BRepTools_ShapeSet::operator new, "None", py::arg("theSize"));
// cls_BRepTools_ShapeSet.def_static("operator delete_", (void (*)(void *)) &BRepTools_ShapeSet::operator delete, "None", py::arg("theAddress"));
// cls_BRepTools_ShapeSet.def_static("operator new[]_", (void * (*)(size_t)) &BRepTools_ShapeSet::operator new[], "None", py::arg("theSize"));
// cls_BRepTools_ShapeSet.def_static("operator delete[]_", (void (*)(void *)) &BRepTools_ShapeSet::operator delete[], "None", py::arg("theAddress"));
// cls_BRepTools_ShapeSet.def_static("operator new_", (void * (*)(size_t, void *)) &BRepTools_ShapeSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepTools_ShapeSet.def_static("operator delete_", (void (*)(void *, void *)) &BRepTools_ShapeSet::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepTools_ShapeSet.def("Clear", (void (BRepTools_ShapeSet::*)()) &BRepTools_ShapeSet::Clear, "Clears the content of the set.");
cls_BRepTools_ShapeSet.def("AddGeometry", (void (BRepTools_ShapeSet::*)(const TopoDS_Shape &)) &BRepTools_ShapeSet::AddGeometry, "Stores the goemetry of <S>.", py::arg("S"));
cls_BRepTools_ShapeSet.def("DumpGeometry", (void (BRepTools_ShapeSet::*)(Standard_OStream &) const) &BRepTools_ShapeSet::DumpGeometry, "Dumps the geometry of me on the stream <OS>.", py::arg("OS"));
cls_BRepTools_ShapeSet.def("WriteGeometry", (void (BRepTools_ShapeSet::*)(Standard_OStream &)) &BRepTools_ShapeSet::WriteGeometry, "Writes the geometry of me on the stream <OS> in a format that can be read back by Read.", py::arg("OS"));
cls_BRepTools_ShapeSet.def("ReadGeometry", (void (BRepTools_ShapeSet::*)(Standard_IStream &)) &BRepTools_ShapeSet::ReadGeometry, "Reads the geometry of me from the stream <IS>.", py::arg("IS"));
cls_BRepTools_ShapeSet.def("DumpGeometry", (void (BRepTools_ShapeSet::*)(const TopoDS_Shape &, Standard_OStream &) const) &BRepTools_ShapeSet::DumpGeometry, "Dumps the geometry of <S> on the stream <OS>.", py::arg("S"), py::arg("OS"));
cls_BRepTools_ShapeSet.def("WriteGeometry", (void (BRepTools_ShapeSet::*)(const TopoDS_Shape &, Standard_OStream &) const) &BRepTools_ShapeSet::WriteGeometry, "Writes the geometry of <S> on the stream <OS> in a format that can be read back by Read.", py::arg("S"), py::arg("OS"));
cls_BRepTools_ShapeSet.def("ReadGeometry", (void (BRepTools_ShapeSet::*)(const TopAbs_ShapeEnum, Standard_IStream &, TopoDS_Shape &)) &BRepTools_ShapeSet::ReadGeometry, "Reads the geometry of a shape of type <T> from the stream <IS> and returns it in <S>.", py::arg("T"), py::arg("IS"), py::arg("S"));
cls_BRepTools_ShapeSet.def("AddShapes", (void (BRepTools_ShapeSet::*)(TopoDS_Shape &, const TopoDS_Shape &)) &BRepTools_ShapeSet::AddShapes, "Inserts the shape <S2> in the shape <S1>. This method must be redefined to use the correct builder.", py::arg("S1"), py::arg("S2"));
cls_BRepTools_ShapeSet.def("Check", (void (BRepTools_ShapeSet::*)(const TopAbs_ShapeEnum, TopoDS_Shape &)) &BRepTools_ShapeSet::Check, "None", py::arg("T"), py::arg("S"));
cls_BRepTools_ShapeSet.def("ReadPolygon3D", (void (BRepTools_ShapeSet::*)(Standard_IStream &)) &BRepTools_ShapeSet::ReadPolygon3D, "Reads the 3d polygons of me from the stream <IS>.", py::arg("IS"));
cls_BRepTools_ShapeSet.def("WritePolygon3D", [](BRepTools_ShapeSet &self, Standard_OStream & a0) -> void { return self.WritePolygon3D(a0); });
cls_BRepTools_ShapeSet.def("WritePolygon3D", (void (BRepTools_ShapeSet::*)(Standard_OStream &, const Standard_Boolean) const) &BRepTools_ShapeSet::WritePolygon3D, "Writes the 3d polygons on the stream <OS> in a format that can be read back by Read.", py::arg("OS"), py::arg("Compact"));
cls_BRepTools_ShapeSet.def("DumpPolygon3D", (void (BRepTools_ShapeSet::*)(Standard_OStream &) const) &BRepTools_ShapeSet::DumpPolygon3D, "Dumps the 3d polygons on the stream <OS>.", py::arg("OS"));
cls_BRepTools_ShapeSet.def("ReadTriangulation", (void (BRepTools_ShapeSet::*)(Standard_IStream &)) &BRepTools_ShapeSet::ReadTriangulation, "Reads the triangulation of me from the stream <IS>.", py::arg("IS"));
cls_BRepTools_ShapeSet.def("WriteTriangulation", [](BRepTools_ShapeSet &self, Standard_OStream & a0) -> void { return self.WriteTriangulation(a0); });
cls_BRepTools_ShapeSet.def("WriteTriangulation", (void (BRepTools_ShapeSet::*)(Standard_OStream &, const Standard_Boolean) const) &BRepTools_ShapeSet::WriteTriangulation, "Writes the triangulation on the stream <OS> in a format that can be read back by Read.", py::arg("OS"), py::arg("Compact"));
cls_BRepTools_ShapeSet.def("DumpTriangulation", (void (BRepTools_ShapeSet::*)(Standard_OStream &) const) &BRepTools_ShapeSet::DumpTriangulation, "Dumps the triangulation on the stream <OS>.", py::arg("OS"));
cls_BRepTools_ShapeSet.def("ReadPolygonOnTriangulation", (void (BRepTools_ShapeSet::*)(Standard_IStream &)) &BRepTools_ShapeSet::ReadPolygonOnTriangulation, "Reads the polygons on triangulation of me from the stream <IS>.", py::arg("IS"));
cls_BRepTools_ShapeSet.def("WritePolygonOnTriangulation", [](BRepTools_ShapeSet &self, Standard_OStream & a0) -> void { return self.WritePolygonOnTriangulation(a0); });
cls_BRepTools_ShapeSet.def("WritePolygonOnTriangulation", (void (BRepTools_ShapeSet::*)(Standard_OStream &, const Standard_Boolean) const) &BRepTools_ShapeSet::WritePolygonOnTriangulation, "Writes the polygons on triangulation on the stream <OS> in a format that can be read back by Read.", py::arg("OS"), py::arg("Compact"));
cls_BRepTools_ShapeSet.def("DumpPolygonOnTriangulation", (void (BRepTools_ShapeSet::*)(Standard_OStream &) const) &BRepTools_ShapeSet::DumpPolygonOnTriangulation, "Dumps the polygons on triangulation on the stream <OS>.", py::arg("OS"));

// CLASS: BREPTOOLS_SUBSTITUTION
py::class_<BRepTools_Substitution> cls_BRepTools_Substitution(mod, "BRepTools_Substitution", "A tool to substitute subshapes by other shapes.");

// Constructors
cls_BRepTools_Substitution.def(py::init<>());

// Methods
// cls_BRepTools_Substitution.def_static("operator new_", (void * (*)(size_t)) &BRepTools_Substitution::operator new, "None", py::arg("theSize"));
// cls_BRepTools_Substitution.def_static("operator delete_", (void (*)(void *)) &BRepTools_Substitution::operator delete, "None", py::arg("theAddress"));
// cls_BRepTools_Substitution.def_static("operator new[]_", (void * (*)(size_t)) &BRepTools_Substitution::operator new[], "None", py::arg("theSize"));
// cls_BRepTools_Substitution.def_static("operator delete[]_", (void (*)(void *)) &BRepTools_Substitution::operator delete[], "None", py::arg("theAddress"));
// cls_BRepTools_Substitution.def_static("operator new_", (void * (*)(size_t, void *)) &BRepTools_Substitution::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepTools_Substitution.def_static("operator delete_", (void (*)(void *, void *)) &BRepTools_Substitution::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepTools_Substitution.def("Clear", (void (BRepTools_Substitution::*)()) &BRepTools_Substitution::Clear, "Reset all the fields.");
cls_BRepTools_Substitution.def("Substitute", (void (BRepTools_Substitution::*)(const TopoDS_Shape &, const TopTools_ListOfShape &)) &BRepTools_Substitution::Substitute, "<Oldshape> will be replaced by <NewShapes>.", py::arg("OldShape"), py::arg("NewShapes"));
cls_BRepTools_Substitution.def("Build", (void (BRepTools_Substitution::*)(const TopoDS_Shape &)) &BRepTools_Substitution::Build, "Build NewShape from <S> if its subshapes has modified.", py::arg("S"));
cls_BRepTools_Substitution.def("IsCopied", (Standard_Boolean (BRepTools_Substitution::*)(const TopoDS_Shape &) const) &BRepTools_Substitution::IsCopied, "Returns True if <S> has been replaced .", py::arg("S"));
cls_BRepTools_Substitution.def("Copy", (const TopTools_ListOfShape & (BRepTools_Substitution::*)(const TopoDS_Shape &) const) &BRepTools_Substitution::Copy, "Returns the set of shapes substitued to <S> .", py::arg("S"));

// CLASS: BREPTOOLS_TRSFMODIFICATION
py::class_<BRepTools_TrsfModification, opencascade::handle<BRepTools_TrsfModification>, BRepTools_Modification> cls_BRepTools_TrsfModification(mod, "BRepTools_TrsfModification", "Describes a modification that uses a gp_Trsf to change the geometry of a shape. All functions return true and transform the geometry of the shape.");

// Constructors
cls_BRepTools_TrsfModification.def(py::init<const gp_Trsf &>(), py::arg("T"));

// Methods
cls_BRepTools_TrsfModification.def("Trsf", (gp_Trsf & (BRepTools_TrsfModification::*)()) &BRepTools_TrsfModification::Trsf, "Provides access to the gp_Trsf associated with this modification. The transformation can be changed.");
cls_BRepTools_TrsfModification.def("NewSurface", [](BRepTools_TrsfModification &self, const TopoDS_Face & F, opencascade::handle<Geom_Surface> & S, TopLoc_Location & L, Standard_Real & Tol, Standard_Boolean & RevWires, Standard_Boolean & RevFace){ Standard_Boolean rv = self.NewSurface(F, S, L, Tol, RevWires, RevFace); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Boolean &, Standard_Boolean &>(rv, Tol, RevWires, RevFace); }, "Returns true if the face F has been modified. If the face has been modified: - S is the new geometry of the face, - L is its new location, and - Tol is the new tolerance. RevWires is set to true when the modification reverses the normal of the surface (the wires have to be reversed). RevFace is set to true if the orientation of the modified face changes in the shells which contain it. For this class, RevFace returns true if the gp_Trsf associated with this modification is negative.", py::arg("F"), py::arg("S"), py::arg("L"), py::arg("Tol"), py::arg("RevWires"), py::arg("RevFace"));
cls_BRepTools_TrsfModification.def("NewCurve", [](BRepTools_TrsfModification &self, const TopoDS_Edge & E, opencascade::handle<Geom_Curve> & C, TopLoc_Location & L, Standard_Real & Tol){ Standard_Boolean rv = self.NewCurve(E, C, L, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "Returns true if the edge E has been modified. If the edge has been modified: - C is the new geometric support of the edge, - L is the new location, and - Tol is the new tolerance. If the edge has not been modified, this function returns false, and the values of C, L and Tol are not significant.", py::arg("E"), py::arg("C"), py::arg("L"), py::arg("Tol"));
cls_BRepTools_TrsfModification.def("NewPoint", [](BRepTools_TrsfModification &self, const TopoDS_Vertex & V, gp_Pnt & P, Standard_Real & Tol){ Standard_Boolean rv = self.NewPoint(V, P, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "Returns true if the vertex V has been modified. If the vertex has been modified: - P is the new geometry of the vertex, and - Tol is the new tolerance. If the vertex has not been modified this function returns false, and the values of P and Tol are not significant.", py::arg("V"), py::arg("P"), py::arg("Tol"));
cls_BRepTools_TrsfModification.def("NewCurve2d", [](BRepTools_TrsfModification &self, const TopoDS_Edge & E, const TopoDS_Face & F, const TopoDS_Edge & NewE, const TopoDS_Face & NewF, opencascade::handle<Geom2d_Curve> & C, Standard_Real & Tol){ Standard_Boolean rv = self.NewCurve2d(E, F, NewE, NewF, C, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "Returns true if the edge E has a new curve on surface on the face F. If a new curve exists: - C is the new geometric support of the edge, - L is the new location, and - Tol the new tolerance. If no new curve exists, this function returns false, and the values of C, L and Tol are not significant.", py::arg("E"), py::arg("F"), py::arg("NewE"), py::arg("NewF"), py::arg("C"), py::arg("Tol"));
cls_BRepTools_TrsfModification.def("NewParameter", [](BRepTools_TrsfModification &self, const TopoDS_Vertex & V, const TopoDS_Edge & E, Standard_Real & P, Standard_Real & Tol){ Standard_Boolean rv = self.NewParameter(V, E, P, Tol); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, P, Tol); }, "Returns true if the Vertex V has a new parameter on the edge E. If a new parameter exists: - P is the parameter, and - Tol is the new tolerance. If no new parameter exists, this function returns false, and the values of P and Tol are not significant.", py::arg("V"), py::arg("E"), py::arg("P"), py::arg("Tol"));
cls_BRepTools_TrsfModification.def("Continuity", (GeomAbs_Shape (BRepTools_TrsfModification::*)(const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &, const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &)) &BRepTools_TrsfModification::Continuity, "Returns the continuity of <NewE> between <NewF1> and <NewF2>.", py::arg("E"), py::arg("F1"), py::arg("F2"), py::arg("NewE"), py::arg("NewF1"), py::arg("NewF2"));
cls_BRepTools_TrsfModification.def_static("get_type_name_", (const char * (*)()) &BRepTools_TrsfModification::get_type_name, "None");
cls_BRepTools_TrsfModification.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepTools_TrsfModification::get_type_descriptor, "None");
cls_BRepTools_TrsfModification.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepTools_TrsfModification::*)() const) &BRepTools_TrsfModification::DynamicType, "None");


}
