/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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
#include <pyOCCT_Common.hpp>

#include <IGESData_IGESEntity.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_HArray1OfIGESEntity.hxx>
#include <IGESSolid_HArray1OfVertexList.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESSolid_VertexList.hxx>
#include <Standard_Type.hxx>
#include <IGESSolid_EdgeList.hxx>
#include <TColgp_HArray1OfXYZ.hxx>
#include <gp_Pnt.hxx>
#include <IGESBasic_HArray1OfHArray1OfInteger.hxx>
#include <IGESBasic_HArray1OfHArray1OfIGESEntity.hxx>
#include <IGESSolid_Loop.hxx>
#include <IGESSolid_HArray1OfLoop.hxx>
#include <IGESSolid_Face.hxx>
#include <IGESSolid_HArray1OfFace.hxx>
#include <IGESSolid_Shell.hxx>
#include <IGESSolid_HArray1OfShell.hxx>
#include <IGESSolid_ManifoldSolid.hxx>
#include <IGESData_Protocol.hxx>
#include <Interface_Protocol.hxx>
#include <IGESSolid_Protocol.hxx>
#include <gp_XYZ.hxx>
#include <gp_Dir.hxx>
#include <IGESSolid_Block.hxx>
#include <IGESSolid_RightAngularWedge.hxx>
#include <IGESSolid_Cylinder.hxx>
#include <IGESSolid_ConeFrustum.hxx>
#include <IGESSolid_Sphere.hxx>
#include <IGESSolid_Torus.hxx>
#include <IGESSolid_SolidOfRevolution.hxx>
#include <IGESSolid_SolidOfLinearExtrusion.hxx>
#include <IGESSolid_Ellipsoid.hxx>
#include <IGESSolid_BooleanTree.hxx>
#include <IGESSolid_SelectedComponent.hxx>
#include <IGESGeom_HArray1OfTransformationMatrix.hxx>
#include <IGESGeom_TransformationMatrix.hxx>
#include <IGESSolid_SolidAssembly.hxx>
#include <IGESGeom_Point.hxx>
#include <IGESGeom_Direction.hxx>
#include <IGESSolid_PlaneSurface.hxx>
#include <IGESSolid_CylindricalSurface.hxx>
#include <IGESSolid_ConicalSurface.hxx>
#include <IGESSolid_SphericalSurface.hxx>
#include <IGESSolid_ToroidalSurface.hxx>
#include <IGESSolid_SolidInstance.hxx>
#include <IGESData_IGESReaderData.hxx>
#include <IGESData_ParamReader.hxx>
#include <IGESData_IGESWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <IGESData_DirChecker.hxx>
#include <Interface_ShareTool.hxx>
#include <Interface_Check.hxx>
#include <Interface_CopyTool.hxx>
#include <IGESData_IGESDumper.hxx>
#include <Message_Messenger.hxx>
#include <IGESSolid_ToolBlock.hxx>
#include <IGESSolid_ToolRightAngularWedge.hxx>
#include <IGESSolid_ToolCylinder.hxx>
#include <IGESSolid_ToolConeFrustum.hxx>
#include <IGESSolid_ToolSphere.hxx>
#include <IGESSolid_ToolTorus.hxx>
#include <IGESSolid_ToolSolidOfRevolution.hxx>
#include <IGESSolid_ToolSolidOfLinearExtrusion.hxx>
#include <IGESSolid_ToolEllipsoid.hxx>
#include <IGESSolid_ToolBooleanTree.hxx>
#include <IGESSolid_ToolSelectedComponent.hxx>
#include <IGESSolid_ToolSolidAssembly.hxx>
#include <IGESSolid_ToolManifoldSolid.hxx>
#include <IGESSolid_ToolPlaneSurface.hxx>
#include <IGESSolid_ToolCylindricalSurface.hxx>
#include <IGESSolid_ToolConicalSurface.hxx>
#include <IGESSolid_ToolSphericalSurface.hxx>
#include <IGESSolid_ToolToroidalSurface.hxx>
#include <IGESSolid_ToolSolidInstance.hxx>
#include <IGESSolid_ToolVertexList.hxx>
#include <IGESSolid_ToolEdgeList.hxx>
#include <IGESSolid_ToolLoop.hxx>
#include <IGESSolid_ToolFace.hxx>
#include <IGESSolid_ToolShell.hxx>
#include <IGESData_ReadWriteModule.hxx>
#include <IGESSolid_ReadWriteModule.hxx>
#include <IGESData_GeneralModule.hxx>
#include <Standard_Transient.hxx>
#include <IGESSolid_GeneralModule.hxx>
#include <IGESData_SpecificModule.hxx>
#include <IGESSolid_SpecificModule.hxx>
#include <IGESSolid_TopoBuilder.hxx>
#include <IGESSolid.hxx>
#include <NCollection_Array1.hxx>
#include <IGESSolid_Array1OfLoop.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <IGESSolid_Array1OfFace.hxx>
#include <IGESSolid_Array1OfShell.hxx>
#include <IGESSolid_Array1OfVertexList.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(IGESSolid, mod) {

	// IMPORT
	py::module::import("OCCT.IGESData");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.TColgp");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.IGESBasic");
	py::module::import("OCCT.Interface");
	py::module::import("OCCT.IGESGeom");
	py::module::import("OCCT.Message");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_EdgeList.hxx
	py::class_<IGESSolid_EdgeList, opencascade::handle<IGESSolid_EdgeList>, IGESData_IGESEntity> cls_IGESSolid_EdgeList(mod, "IGESSolid_EdgeList", "defines EdgeList, Type <504> Form <1> in package IGESSolid EdgeList is defined as a segment joining two vertices It contains one or more edge tuples.");
	cls_IGESSolid_EdgeList.def(py::init<>());
	cls_IGESSolid_EdgeList.def("Init", (void (IGESSolid_EdgeList::*)(const opencascade::handle<IGESData_HArray1OfIGESEntity> &, const opencascade::handle<IGESSolid_HArray1OfVertexList> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<IGESSolid_HArray1OfVertexList> &, const opencascade::handle<TColStd_HArray1OfInteger> &)) &IGESSolid_EdgeList::Init, "This method is used to set the fields of the class EdgeList - curves : the model space curves - startVertexList : the vertex list that contains the start vertices - startVertexIndex : the index of the vertex in the corresponding vertex list - endVertexList : the vertex list that contains the end vertices - endVertexIndex : the index of the vertex in the corresponding vertex list raises exception if size of curves,startVertexList,startVertexIndex, endVertexList and endVertexIndex do no match", py::arg("curves"), py::arg("startVertexList"), py::arg("startVertexIndex"), py::arg("endVertexList"), py::arg("endVertexIndex"));
	cls_IGESSolid_EdgeList.def("NbEdges", (Standard_Integer (IGESSolid_EdgeList::*)() const ) &IGESSolid_EdgeList::NbEdges, "returns the number of edges in the edge list");
	cls_IGESSolid_EdgeList.def("Curve", (opencascade::handle<IGESData_IGESEntity> (IGESSolid_EdgeList::*)(const Standard_Integer) const ) &IGESSolid_EdgeList::Curve, "returns the num'th model space curve raises Exception if num <= 0 or num > NbEdges()", py::arg("num"));
	cls_IGESSolid_EdgeList.def("StartVertexList", (opencascade::handle<IGESSolid_VertexList> (IGESSolid_EdgeList::*)(const Standard_Integer) const ) &IGESSolid_EdgeList::StartVertexList, "returns the num'th start vertex list raises Exception if num <= 0 or num > NbEdges()", py::arg("num"));
	cls_IGESSolid_EdgeList.def("StartVertexIndex", (Standard_Integer (IGESSolid_EdgeList::*)(const Standard_Integer) const ) &IGESSolid_EdgeList::StartVertexIndex, "returns the index of num'th start vertex in the corresponding start vertex list raises Exception if num <= 0 or num > NbEdges()", py::arg("num"));
	cls_IGESSolid_EdgeList.def("EndVertexList", (opencascade::handle<IGESSolid_VertexList> (IGESSolid_EdgeList::*)(const Standard_Integer) const ) &IGESSolid_EdgeList::EndVertexList, "returns the num'th end vertex list raises Exception if num <= 0 or num > NbEdges()", py::arg("num"));
	cls_IGESSolid_EdgeList.def("EndVertexIndex", (Standard_Integer (IGESSolid_EdgeList::*)(const Standard_Integer) const ) &IGESSolid_EdgeList::EndVertexIndex, "returns the index of num'th end vertex in the corresponding end vertex list raises Exception if num <= 0 or num > NbEdges()", py::arg("num"));
	cls_IGESSolid_EdgeList.def_static("get_type_name_", (const char * (*)()) &IGESSolid_EdgeList::get_type_name, "None");
	cls_IGESSolid_EdgeList.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_EdgeList::get_type_descriptor, "None");
	cls_IGESSolid_EdgeList.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_EdgeList::*)() const ) &IGESSolid_EdgeList::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_VertexList.hxx
	py::class_<IGESSolid_VertexList, opencascade::handle<IGESSolid_VertexList>, IGESData_IGESEntity> cls_IGESSolid_VertexList(mod, "IGESSolid_VertexList", "defines VertexList, Type <502> Form Number <1> in package IGESSolid A vertex is a point in R3. A vertex is the bound of an edge and can participate in the bounds of a face. It contains one or more vertices.");
	cls_IGESSolid_VertexList.def(py::init<>());
	cls_IGESSolid_VertexList.def("Init", (void (IGESSolid_VertexList::*)(const opencascade::handle<TColgp_HArray1OfXYZ> &)) &IGESSolid_VertexList::Init, "This method is used to set the fields of the class VertexList - vertices : the vertices in the list", py::arg("vertices"));
	cls_IGESSolid_VertexList.def("NbVertices", (Standard_Integer (IGESSolid_VertexList::*)() const ) &IGESSolid_VertexList::NbVertices, "return the number of vertices in the list");
	cls_IGESSolid_VertexList.def("Vertex", (gp_Pnt (IGESSolid_VertexList::*)(const Standard_Integer) const ) &IGESSolid_VertexList::Vertex, "returns the num'th vertex in the list raises exception if num <= 0 or num > NbVertices()", py::arg("num"));
	cls_IGESSolid_VertexList.def_static("get_type_name_", (const char * (*)()) &IGESSolid_VertexList::get_type_name, "None");
	cls_IGESSolid_VertexList.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_VertexList::get_type_descriptor, "None");
	cls_IGESSolid_VertexList.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_VertexList::*)() const ) &IGESSolid_VertexList::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_Loop.hxx
	py::class_<IGESSolid_Loop, opencascade::handle<IGESSolid_Loop>, IGESData_IGESEntity> cls_IGESSolid_Loop(mod, "IGESSolid_Loop", "defines Loop, Type <508> Form Number <1> in package IGESSolid A Loop entity specifies a bound of a face. It represents a connected collection of face boundaries, seams, and poles of a single face.");
	cls_IGESSolid_Loop.def(py::init<>());
	cls_IGESSolid_Loop.def("Init", (void (IGESSolid_Loop::*)(const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<IGESData_HArray1OfIGESEntity> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<IGESBasic_HArray1OfHArray1OfInteger> &, const opencascade::handle<IGESBasic_HArray1OfHArray1OfIGESEntity> &)) &IGESSolid_Loop::Init, "This method is used to set the fields of the class Loop - types : 0 = Edge; 1 = Vertex - edges : Pointer to the EdgeList or VertexList - index : Index of the edge into the EdgeList VertexList entity - orient : Orientation flag of the edge - nbParameterCurves : the number of parameter space curves for each edge - isoparametricFlags : the isoparametric flag of the parameter space curve - curves : the parameter space curves raises exception if length of types, edges, index, orient and nbParameterCurves do not match or the length of isoparametricFlags and curves do not match", py::arg("types"), py::arg("edges"), py::arg("index"), py::arg("orient"), py::arg("nbParameterCurves"), py::arg("isoparametricFlags"), py::arg("curves"));
	cls_IGESSolid_Loop.def("IsBound", (Standard_Boolean (IGESSolid_Loop::*)() const ) &IGESSolid_Loop::IsBound, "Tells if a Loop is a Bound (FN 1) else it is free (FN 0)");
	cls_IGESSolid_Loop.def("SetBound", (void (IGESSolid_Loop::*)(const Standard_Boolean)) &IGESSolid_Loop::SetBound, "Sets or Unset the Bound Status (from Form Number) Default is True", py::arg("bound"));
	cls_IGESSolid_Loop.def("NbEdges", (Standard_Integer (IGESSolid_Loop::*)() const ) &IGESSolid_Loop::NbEdges, "returns the number of edge tuples");
	cls_IGESSolid_Loop.def("EdgeType", (Standard_Integer (IGESSolid_Loop::*)(const Standard_Integer) const ) &IGESSolid_Loop::EdgeType, "returns the type of Index'th edge (0 = Edge, 1 = Vertex) raises exception if Index <= 0 or Index > NbEdges()", py::arg("Index"));
	cls_IGESSolid_Loop.def("Edge", (opencascade::handle<IGESData_IGESEntity> (IGESSolid_Loop::*)(const Standard_Integer) const ) &IGESSolid_Loop::Edge, "return the EdgeList or VertexList corresponding to the Index raises exception if Index <= 0 or Index > NbEdges()", py::arg("Index"));
	cls_IGESSolid_Loop.def("Orientation", (Standard_Boolean (IGESSolid_Loop::*)(const Standard_Integer) const ) &IGESSolid_Loop::Orientation, "returns the orientation flag corresponding to Index'th edge raises exception if Index <= 0 or Index > NbEdges()", py::arg("Index"));
	cls_IGESSolid_Loop.def("NbParameterCurves", (Standard_Integer (IGESSolid_Loop::*)(const Standard_Integer) const ) &IGESSolid_Loop::NbParameterCurves, "return the number of parameter space curves associated with Index'th Edge raises exception if Index <= 0 or Index > NbEdges()", py::arg("Index"));
	cls_IGESSolid_Loop.def("IsIsoparametric", (Standard_Boolean (IGESSolid_Loop::*)(const Standard_Integer, const Standard_Integer) const ) &IGESSolid_Loop::IsIsoparametric, "None", py::arg("EdgeIndex"), py::arg("CurveIndex"));
	cls_IGESSolid_Loop.def("ParametricCurve", (opencascade::handle<IGESData_IGESEntity> (IGESSolid_Loop::*)(const Standard_Integer, const Standard_Integer) const ) &IGESSolid_Loop::ParametricCurve, "returns the CurveIndex'th parameter space curve associated with EdgeIndex'th edge raises exception if EdgeIndex <= 0 or EdgeIndex > NbEdges() or if CurveIndex <= 0 or CurveIndex > NbParameterCurves(EdgeIndex)", py::arg("EdgeIndex"), py::arg("CurveIndex"));
	cls_IGESSolid_Loop.def("ListIndex", (Standard_Integer (IGESSolid_Loop::*)(const Standard_Integer) const ) &IGESSolid_Loop::ListIndex, "raises exception If num <= 0 or num > NbEdges()", py::arg("num"));
	cls_IGESSolid_Loop.def_static("get_type_name_", (const char * (*)()) &IGESSolid_Loop::get_type_name, "None");
	cls_IGESSolid_Loop.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_Loop::get_type_descriptor, "None");
	cls_IGESSolid_Loop.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_Loop::*)() const ) &IGESSolid_Loop::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_Face.hxx
	py::class_<IGESSolid_Face, opencascade::handle<IGESSolid_Face>, IGESData_IGESEntity> cls_IGESSolid_Face(mod, "IGESSolid_Face", "defines Face, Type <510> Form Number <1> in package IGESSolid Face entity is a bound (partial) which has finite area");
	cls_IGESSolid_Face.def(py::init<>());
	cls_IGESSolid_Face.def("Init", (void (IGESSolid_Face::*)(const opencascade::handle<IGESData_IGESEntity> &, const Standard_Boolean, const opencascade::handle<IGESSolid_HArray1OfLoop> &)) &IGESSolid_Face::Init, "This method is used to set the fields of the class Face - aSurface : Pointer to the underlying surface - outerLoopFlag : True means the first loop is the outer loop - loops : Array of loops bounding the face", py::arg("aSurface"), py::arg("outerLoopFlag"), py::arg("loops"));
	cls_IGESSolid_Face.def("Surface", (opencascade::handle<IGESData_IGESEntity> (IGESSolid_Face::*)() const ) &IGESSolid_Face::Surface, "returns the underlying surface of the face");
	cls_IGESSolid_Face.def("NbLoops", (Standard_Integer (IGESSolid_Face::*)() const ) &IGESSolid_Face::NbLoops, "returns the number of the loops bounding the face");
	cls_IGESSolid_Face.def("HasOuterLoop", (Standard_Boolean (IGESSolid_Face::*)() const ) &IGESSolid_Face::HasOuterLoop, "checks whether there is an outer loop or not");
	cls_IGESSolid_Face.def("Loop", (opencascade::handle<IGESSolid_Loop> (IGESSolid_Face::*)(const Standard_Integer) const ) &IGESSolid_Face::Loop, "returns the Index'th loop that bounds the face raises exception if Index < 0 or Index >= NbLoops", py::arg("Index"));
	cls_IGESSolid_Face.def_static("get_type_name_", (const char * (*)()) &IGESSolid_Face::get_type_name, "None");
	cls_IGESSolid_Face.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_Face::get_type_descriptor, "None");
	cls_IGESSolid_Face.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_Face::*)() const ) &IGESSolid_Face::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_Shell.hxx
	py::class_<IGESSolid_Shell, opencascade::handle<IGESSolid_Shell>, IGESData_IGESEntity> cls_IGESSolid_Shell(mod, "IGESSolid_Shell", "defines Shell, Type <514> Form Number <1> in package IGESSolid Shell entity is a connected entity of dimensionality 2 which divides R3 into two arcwise connected open subsets, one of which is finite. Inside of the shell is defined to be the finite region. From IGES-5.3, Form can be <1> for Closed or <2> for Open");
	cls_IGESSolid_Shell.def(py::init<>());
	cls_IGESSolid_Shell.def("Init", (void (IGESSolid_Shell::*)(const opencascade::handle<IGESSolid_HArray1OfFace> &, const opencascade::handle<TColStd_HArray1OfInteger> &)) &IGESSolid_Shell::Init, "This method is used to set the fields of the class Shell - allFaces : the faces comprising the shell - allOrient : the orientation flags of the shell raises exception if length of allFaces & allOrient do not match", py::arg("allFaces"), py::arg("allOrient"));
	cls_IGESSolid_Shell.def("IsClosed", (Standard_Boolean (IGESSolid_Shell::*)() const ) &IGESSolid_Shell::IsClosed, "Tells if a Shell is Closed, i.e. if its FormNumber is 1 (this is the default)");
	cls_IGESSolid_Shell.def("SetClosed", (void (IGESSolid_Shell::*)(const Standard_Boolean)) &IGESSolid_Shell::SetClosed, "Sets or Unsets the Closed status (FormNumber = 1 else 2)", py::arg("closed"));
	cls_IGESSolid_Shell.def("NbFaces", (Standard_Integer (IGESSolid_Shell::*)() const ) &IGESSolid_Shell::NbFaces, "returns the number of the face entities in the shell");
	cls_IGESSolid_Shell.def("Face", (opencascade::handle<IGESSolid_Face> (IGESSolid_Shell::*)(const Standard_Integer) const ) &IGESSolid_Shell::Face, "returns the Index'th face entity of the shell raises exception if Index <= 0 or Index > NbFaces()", py::arg("Index"));
	cls_IGESSolid_Shell.def("Orientation", (Standard_Boolean (IGESSolid_Shell::*)(const Standard_Integer) const ) &IGESSolid_Shell::Orientation, "returns the orientation of Index'th face w.r.t the direction of the underlying surface raises exception if Index <= 0 or Index > NbFaces()", py::arg("Index"));
	cls_IGESSolid_Shell.def_static("get_type_name_", (const char * (*)()) &IGESSolid_Shell::get_type_name, "None");
	cls_IGESSolid_Shell.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_Shell::get_type_descriptor, "None");
	cls_IGESSolid_Shell.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_Shell::*)() const ) &IGESSolid_Shell::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_ManifoldSolid.hxx
	py::class_<IGESSolid_ManifoldSolid, opencascade::handle<IGESSolid_ManifoldSolid>, IGESData_IGESEntity> cls_IGESSolid_ManifoldSolid(mod, "IGESSolid_ManifoldSolid", "defines ManifoldSolid, Type <186> Form Number <0> in package IGESSolid A manifold solid is a bounded, closed, and finite volume in three dimensional Euclidean space");
	cls_IGESSolid_ManifoldSolid.def(py::init<>());
	cls_IGESSolid_ManifoldSolid.def("Init", (void (IGESSolid_ManifoldSolid::*)(const opencascade::handle<IGESSolid_Shell> &, const Standard_Boolean, const opencascade::handle<IGESSolid_HArray1OfShell> &, const opencascade::handle<TColStd_HArray1OfInteger> &)) &IGESSolid_ManifoldSolid::Init, "This method is used to set the fields of the class ManifoldSolid - aShell : pointer to the shell - shellflag : orientation flag of shell - voidShells : the void shells - voidShellFlags : orientation of the void shells raises exception if length of voidShells and voidShellFlags do not match", py::arg("aShell"), py::arg("shellflag"), py::arg("voidShells"), py::arg("voidShellFlags"));
	cls_IGESSolid_ManifoldSolid.def("Shell", (opencascade::handle<IGESSolid_Shell> (IGESSolid_ManifoldSolid::*)() const ) &IGESSolid_ManifoldSolid::Shell, "returns the Shell entity which is being referred");
	cls_IGESSolid_ManifoldSolid.def("OrientationFlag", (Standard_Boolean (IGESSolid_ManifoldSolid::*)() const ) &IGESSolid_ManifoldSolid::OrientationFlag, "returns the orientation flag of the shell");
	cls_IGESSolid_ManifoldSolid.def("NbVoidShells", (Standard_Integer (IGESSolid_ManifoldSolid::*)() const ) &IGESSolid_ManifoldSolid::NbVoidShells, "returns the number of void shells");
	cls_IGESSolid_ManifoldSolid.def("VoidShell", (opencascade::handle<IGESSolid_Shell> (IGESSolid_ManifoldSolid::*)(const Standard_Integer) const ) &IGESSolid_ManifoldSolid::VoidShell, "returns Index'th void shell. raises exception if Index <= 0 or Index > NbVoidShells()", py::arg("Index"));
	cls_IGESSolid_ManifoldSolid.def("VoidOrientationFlag", (Standard_Boolean (IGESSolid_ManifoldSolid::*)(const Standard_Integer) const ) &IGESSolid_ManifoldSolid::VoidOrientationFlag, "returns Index'th orientation flag. raises exception if Index <= 0 or Index > NbVoidShells()", py::arg("Index"));
	cls_IGESSolid_ManifoldSolid.def_static("get_type_name_", (const char * (*)()) &IGESSolid_ManifoldSolid::get_type_name, "None");
	cls_IGESSolid_ManifoldSolid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_ManifoldSolid::get_type_descriptor, "None");
	cls_IGESSolid_ManifoldSolid.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_ManifoldSolid::*)() const ) &IGESSolid_ManifoldSolid::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_Protocol.hxx
	py::class_<IGESSolid_Protocol, opencascade::handle<IGESSolid_Protocol>, IGESData_Protocol> cls_IGESSolid_Protocol(mod, "IGESSolid_Protocol", "Description of Protocol for IGESSolid");
	cls_IGESSolid_Protocol.def(py::init<>());
	cls_IGESSolid_Protocol.def("NbResources", (Standard_Integer (IGESSolid_Protocol::*)() const ) &IGESSolid_Protocol::NbResources, "Gives the count of Resource Protocol. Here, one (Protocol from IGESGeom)");
	cls_IGESSolid_Protocol.def("Resource", (opencascade::handle<Interface_Protocol> (IGESSolid_Protocol::*)(const Standard_Integer) const ) &IGESSolid_Protocol::Resource, "Returns a Resource, given a rank.", py::arg("num"));
	cls_IGESSolid_Protocol.def("TypeNumber", (Standard_Integer (IGESSolid_Protocol::*)(const opencascade::handle<Standard_Type> &) const ) &IGESSolid_Protocol::TypeNumber, "Returns a Case Number, specific of each recognized Type This Case Number is then used in Libraries : the various Modules attached to this class of Protocol must use them in accordance (for a given value of TypeNumber, they must consider the same Type as the Protocol defines)", py::arg("atype"));
	cls_IGESSolid_Protocol.def_static("get_type_name_", (const char * (*)()) &IGESSolid_Protocol::get_type_name, "None");
	cls_IGESSolid_Protocol.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_Protocol::get_type_descriptor, "None");
	cls_IGESSolid_Protocol.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_Protocol::*)() const ) &IGESSolid_Protocol::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_Block.hxx
	py::class_<IGESSolid_Block, opencascade::handle<IGESSolid_Block>, IGESData_IGESEntity> cls_IGESSolid_Block(mod, "IGESSolid_Block", "defines Block, Type <150> Form Number <0> in package IGESSolid The Block is a rectangular parallelopiped, defined with one vertex at (X1, Y1, Z1) and three edges lying along the local +X, +Y, +Z axes.");
	cls_IGESSolid_Block.def(py::init<>());
	cls_IGESSolid_Block.def("Init", (void (IGESSolid_Block::*)(const gp_XYZ &, const gp_XYZ &, const gp_XYZ &, const gp_XYZ &)) &IGESSolid_Block::Init, "This method is used to set the fields of the class Block - aSize : Length in each local directions - aCorner : Corner point coordinates. Default (0,0,0) - aXAxis : Unit vector defining local X-axis default (1,0,0) - aZAxis : Unit vector defining local Z-axis default (0,0,1)", py::arg("aSize"), py::arg("aCorner"), py::arg("aXAxis"), py::arg("aZAxis"));
	cls_IGESSolid_Block.def("Size", (gp_XYZ (IGESSolid_Block::*)() const ) &IGESSolid_Block::Size, "returns the size of the block");
	cls_IGESSolid_Block.def("XLength", (Standard_Real (IGESSolid_Block::*)() const ) &IGESSolid_Block::XLength, "returns the length of the Block along the local X-direction");
	cls_IGESSolid_Block.def("YLength", (Standard_Real (IGESSolid_Block::*)() const ) &IGESSolid_Block::YLength, "returns the length of the Block along the local Y-direction");
	cls_IGESSolid_Block.def("ZLength", (Standard_Real (IGESSolid_Block::*)() const ) &IGESSolid_Block::ZLength, "returns the length of the Block along the local Z-direction");
	cls_IGESSolid_Block.def("Corner", (gp_Pnt (IGESSolid_Block::*)() const ) &IGESSolid_Block::Corner, "returns the corner point coordinates of the Block");
	cls_IGESSolid_Block.def("TransformedCorner", (gp_Pnt (IGESSolid_Block::*)() const ) &IGESSolid_Block::TransformedCorner, "returns the corner point coordinates of the Block after applying the TransformationMatrix");
	cls_IGESSolid_Block.def("XAxis", (gp_Dir (IGESSolid_Block::*)() const ) &IGESSolid_Block::XAxis, "returns the direction defining the local X-axis");
	cls_IGESSolid_Block.def("TransformedXAxis", (gp_Dir (IGESSolid_Block::*)() const ) &IGESSolid_Block::TransformedXAxis, "returns the direction defining the local X-axis after applying TransformationMatrix");
	cls_IGESSolid_Block.def("YAxis", (gp_Dir (IGESSolid_Block::*)() const ) &IGESSolid_Block::YAxis, "returns the direction defining the local Y-axis it is the cross product of ZAxis and XAxis");
	cls_IGESSolid_Block.def("TransformedYAxis", (gp_Dir (IGESSolid_Block::*)() const ) &IGESSolid_Block::TransformedYAxis, "returns the direction defining the local Y-axis after applying TransformationMatrix");
	cls_IGESSolid_Block.def("ZAxis", (gp_Dir (IGESSolid_Block::*)() const ) &IGESSolid_Block::ZAxis, "returns the direction defining the local X-axis");
	cls_IGESSolid_Block.def("TransformedZAxis", (gp_Dir (IGESSolid_Block::*)() const ) &IGESSolid_Block::TransformedZAxis, "returns the direction defining the local Z-axis after applying TransformationMatrix");
	cls_IGESSolid_Block.def_static("get_type_name_", (const char * (*)()) &IGESSolid_Block::get_type_name, "None");
	cls_IGESSolid_Block.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_Block::get_type_descriptor, "None");
	cls_IGESSolid_Block.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_Block::*)() const ) &IGESSolid_Block::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_RightAngularWedge.hxx
	py::class_<IGESSolid_RightAngularWedge, opencascade::handle<IGESSolid_RightAngularWedge>, IGESData_IGESEntity> cls_IGESSolid_RightAngularWedge(mod, "IGESSolid_RightAngularWedge", "defines RightAngularWedge, Type <152> Form Number <0> in package IGESSolid A right angular wedge is a triangular/trapezoidal prism");
	cls_IGESSolid_RightAngularWedge.def(py::init<>());
	cls_IGESSolid_RightAngularWedge.def("Init", (void (IGESSolid_RightAngularWedge::*)(const gp_XYZ &, const Standard_Real, const gp_XYZ &, const gp_XYZ &, const gp_XYZ &)) &IGESSolid_RightAngularWedge::Init, "This method is used to set the fields of the class RightAngularWedge - aSize : the lengths along the local axes - lowX : the length at the smaller X-side - aCorner : the corner point coordinates default (0,0,0) - anXAxis : the unit vector defining local X-axis default (1,0,0) - anZAxis : the unit vector defining local Z-axis default (0,0,1)", py::arg("aSize"), py::arg("lowX"), py::arg("aCorner"), py::arg("anXAxis"), py::arg("anZAxis"));
	cls_IGESSolid_RightAngularWedge.def("Size", (gp_XYZ (IGESSolid_RightAngularWedge::*)() const ) &IGESSolid_RightAngularWedge::Size, "returns the size");
	cls_IGESSolid_RightAngularWedge.def("XBigLength", (Standard_Real (IGESSolid_RightAngularWedge::*)() const ) &IGESSolid_RightAngularWedge::XBigLength, "returns the length along the local X-axis");
	cls_IGESSolid_RightAngularWedge.def("XSmallLength", (Standard_Real (IGESSolid_RightAngularWedge::*)() const ) &IGESSolid_RightAngularWedge::XSmallLength, "returns the smaller length along the local X-direction at Y=LY");
	cls_IGESSolid_RightAngularWedge.def("YLength", (Standard_Real (IGESSolid_RightAngularWedge::*)() const ) &IGESSolid_RightAngularWedge::YLength, "returns the length along the local Y-axis");
	cls_IGESSolid_RightAngularWedge.def("ZLength", (Standard_Real (IGESSolid_RightAngularWedge::*)() const ) &IGESSolid_RightAngularWedge::ZLength, "returns the length along the local Z-axis");
	cls_IGESSolid_RightAngularWedge.def("Corner", (gp_Pnt (IGESSolid_RightAngularWedge::*)() const ) &IGESSolid_RightAngularWedge::Corner, "returns the corner point coordinates");
	cls_IGESSolid_RightAngularWedge.def("TransformedCorner", (gp_Pnt (IGESSolid_RightAngularWedge::*)() const ) &IGESSolid_RightAngularWedge::TransformedCorner, "returns the corner point coordinates after applying TransformationMatrix");
	cls_IGESSolid_RightAngularWedge.def("XAxis", (gp_Dir (IGESSolid_RightAngularWedge::*)() const ) &IGESSolid_RightAngularWedge::XAxis, "returns the direction defining the local X-axis");
	cls_IGESSolid_RightAngularWedge.def("TransformedXAxis", (gp_Dir (IGESSolid_RightAngularWedge::*)() const ) &IGESSolid_RightAngularWedge::TransformedXAxis, "returns the direction defining the local X-axis after applying the TransformationMatrix");
	cls_IGESSolid_RightAngularWedge.def("YAxis", (gp_Dir (IGESSolid_RightAngularWedge::*)() const ) &IGESSolid_RightAngularWedge::YAxis, "returns the direction defining the local Y-axis it is got by taking the cross product of ZAxis and XAxis");
	cls_IGESSolid_RightAngularWedge.def("TransformedYAxis", (gp_Dir (IGESSolid_RightAngularWedge::*)() const ) &IGESSolid_RightAngularWedge::TransformedYAxis, "returns the direction defining the local Y-axis after applying the TransformationMatrix");
	cls_IGESSolid_RightAngularWedge.def("ZAxis", (gp_Dir (IGESSolid_RightAngularWedge::*)() const ) &IGESSolid_RightAngularWedge::ZAxis, "returns the direction defining the local Z-axis");
	cls_IGESSolid_RightAngularWedge.def("TransformedZAxis", (gp_Dir (IGESSolid_RightAngularWedge::*)() const ) &IGESSolid_RightAngularWedge::TransformedZAxis, "returns the direction defining the local Z-axis after applying the TransformationMatrix");
	cls_IGESSolid_RightAngularWedge.def_static("get_type_name_", (const char * (*)()) &IGESSolid_RightAngularWedge::get_type_name, "None");
	cls_IGESSolid_RightAngularWedge.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_RightAngularWedge::get_type_descriptor, "None");
	cls_IGESSolid_RightAngularWedge.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_RightAngularWedge::*)() const ) &IGESSolid_RightAngularWedge::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_Cylinder.hxx
	py::class_<IGESSolid_Cylinder, opencascade::handle<IGESSolid_Cylinder>, IGESData_IGESEntity> cls_IGESSolid_Cylinder(mod, "IGESSolid_Cylinder", "defines Cylinder, Type <154> Form Number <0> in package IGESSolid This defines a solid cylinder");
	cls_IGESSolid_Cylinder.def(py::init<>());
	cls_IGESSolid_Cylinder.def("Init", (void (IGESSolid_Cylinder::*)(const Standard_Real, const Standard_Real, const gp_XYZ &, const gp_XYZ &)) &IGESSolid_Cylinder::Init, "This method is used to set the fields of the class Cylinder - aHeight : Cylinder height - aRadius : Cylinder radius - aCenter : First face center coordinates (default (0,0,0)) - anAxis : Unit vector in axis direction (default (0,0,1))", py::arg("aHeight"), py::arg("aRadius"), py::arg("aCenter"), py::arg("anAxis"));
	cls_IGESSolid_Cylinder.def("Height", (Standard_Real (IGESSolid_Cylinder::*)() const ) &IGESSolid_Cylinder::Height, "returns the cylinder height");
	cls_IGESSolid_Cylinder.def("Radius", (Standard_Real (IGESSolid_Cylinder::*)() const ) &IGESSolid_Cylinder::Radius, "returns the cylinder radius");
	cls_IGESSolid_Cylinder.def("FaceCenter", (gp_Pnt (IGESSolid_Cylinder::*)() const ) &IGESSolid_Cylinder::FaceCenter, "returns the first face center coordinates.");
	cls_IGESSolid_Cylinder.def("TransformedFaceCenter", (gp_Pnt (IGESSolid_Cylinder::*)() const ) &IGESSolid_Cylinder::TransformedFaceCenter, "returns the first face center after applying TransformationMatrix");
	cls_IGESSolid_Cylinder.def("Axis", (gp_Dir (IGESSolid_Cylinder::*)() const ) &IGESSolid_Cylinder::Axis, "returns the vector in axis direction");
	cls_IGESSolid_Cylinder.def("TransformedAxis", (gp_Dir (IGESSolid_Cylinder::*)() const ) &IGESSolid_Cylinder::TransformedAxis, "returns the vector in axis direction after applying TransformationMatrix");
	cls_IGESSolid_Cylinder.def_static("get_type_name_", (const char * (*)()) &IGESSolid_Cylinder::get_type_name, "None");
	cls_IGESSolid_Cylinder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_Cylinder::get_type_descriptor, "None");
	cls_IGESSolid_Cylinder.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_Cylinder::*)() const ) &IGESSolid_Cylinder::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_ConeFrustum.hxx
	py::class_<IGESSolid_ConeFrustum, opencascade::handle<IGESSolid_ConeFrustum>, IGESData_IGESEntity> cls_IGESSolid_ConeFrustum(mod, "IGESSolid_ConeFrustum", "defines ConeFrustum, Type <156> Form Number <0> in package IGESSolid The Cone Frustum is defined by the center of the larger circular face of the frustum, its radius, a unit vector in the axis direction, a height in this direction and a second circular face with radius which is lesser than the first face.");
	cls_IGESSolid_ConeFrustum.def(py::init<>());
	cls_IGESSolid_ConeFrustum.def("Init", (void (IGESSolid_ConeFrustum::*)(const Standard_Real, const Standard_Real, const Standard_Real, const gp_XYZ &, const gp_XYZ &)) &IGESSolid_ConeFrustum::Init, "This method is used to set the fields of the class ConeFrustum - Ht : the Height of cone - R1 : Radius of the larger face - R2 : Radius of the smaller face (default 0) - Center : Center of the larger face (default (0,0,0)) - anAxis : Unit vector in axis direction (default (0,0,1))", py::arg("Ht"), py::arg("R1"), py::arg("R2"), py::arg("Center"), py::arg("anAxis"));
	cls_IGESSolid_ConeFrustum.def("Height", (Standard_Real (IGESSolid_ConeFrustum::*)() const ) &IGESSolid_ConeFrustum::Height, "returns the height of the cone frustum");
	cls_IGESSolid_ConeFrustum.def("LargerRadius", (Standard_Real (IGESSolid_ConeFrustum::*)() const ) &IGESSolid_ConeFrustum::LargerRadius, "returns the radius of the larger face of the cone frustum");
	cls_IGESSolid_ConeFrustum.def("SmallerRadius", (Standard_Real (IGESSolid_ConeFrustum::*)() const ) &IGESSolid_ConeFrustum::SmallerRadius, "returns the radius of the second face of the cone frustum");
	cls_IGESSolid_ConeFrustum.def("FaceCenter", (gp_Pnt (IGESSolid_ConeFrustum::*)() const ) &IGESSolid_ConeFrustum::FaceCenter, "returns the center of the larger face of the cone frustum");
	cls_IGESSolid_ConeFrustum.def("TransformedFaceCenter", (gp_Pnt (IGESSolid_ConeFrustum::*)() const ) &IGESSolid_ConeFrustum::TransformedFaceCenter, "returns the center of the larger face of the cone frustum after applying TransformationMatrix");
	cls_IGESSolid_ConeFrustum.def("Axis", (gp_Dir (IGESSolid_ConeFrustum::*)() const ) &IGESSolid_ConeFrustum::Axis, "returns the direction of the axis of the cone frustum");
	cls_IGESSolid_ConeFrustum.def("TransformedAxis", (gp_Dir (IGESSolid_ConeFrustum::*)() const ) &IGESSolid_ConeFrustum::TransformedAxis, "returns the direction of the axis of the cone frustum after applying TransformationMatrix");
	cls_IGESSolid_ConeFrustum.def_static("get_type_name_", (const char * (*)()) &IGESSolid_ConeFrustum::get_type_name, "None");
	cls_IGESSolid_ConeFrustum.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_ConeFrustum::get_type_descriptor, "None");
	cls_IGESSolid_ConeFrustum.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_ConeFrustum::*)() const ) &IGESSolid_ConeFrustum::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_Sphere.hxx
	py::class_<IGESSolid_Sphere, opencascade::handle<IGESSolid_Sphere>, IGESData_IGESEntity> cls_IGESSolid_Sphere(mod, "IGESSolid_Sphere", "defines Sphere, Type <158> Form Number <0> in package IGESSolid This defines a sphere with a center and radius");
	cls_IGESSolid_Sphere.def(py::init<>());
	cls_IGESSolid_Sphere.def("Init", (void (IGESSolid_Sphere::*)(const Standard_Real, const gp_XYZ &)) &IGESSolid_Sphere::Init, "This method is used to set the fields of the class Sphere - aRadius : the radius of the sphere - aCenter : the center point coordinates (default (0,0,0))", py::arg("aRadius"), py::arg("aCenter"));
	cls_IGESSolid_Sphere.def("Radius", (Standard_Real (IGESSolid_Sphere::*)() const ) &IGESSolid_Sphere::Radius, "returns the radius of the sphere");
	cls_IGESSolid_Sphere.def("Center", (gp_Pnt (IGESSolid_Sphere::*)() const ) &IGESSolid_Sphere::Center, "returns the center of the sphere");
	cls_IGESSolid_Sphere.def("TransformedCenter", (gp_Pnt (IGESSolid_Sphere::*)() const ) &IGESSolid_Sphere::TransformedCenter, "returns the center of the sphere after applying TransformationMatrix");
	cls_IGESSolid_Sphere.def_static("get_type_name_", (const char * (*)()) &IGESSolid_Sphere::get_type_name, "None");
	cls_IGESSolid_Sphere.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_Sphere::get_type_descriptor, "None");
	cls_IGESSolid_Sphere.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_Sphere::*)() const ) &IGESSolid_Sphere::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_Torus.hxx
	py::class_<IGESSolid_Torus, opencascade::handle<IGESSolid_Torus>, IGESData_IGESEntity> cls_IGESSolid_Torus(mod, "IGESSolid_Torus", "defines Torus, Type <160> Form Number <0> in package IGESSolid A Torus is a solid formed by revolving a circular disc about a specified coplanar axis.");
	cls_IGESSolid_Torus.def(py::init<>());
	cls_IGESSolid_Torus.def("Init", (void (IGESSolid_Torus::*)(const Standard_Real, const Standard_Real, const gp_XYZ &, const gp_XYZ &)) &IGESSolid_Torus::Init, "This method is used to set the fields of the class Torus - R1 : distance from center of torus to center of circular disc to be revolved - R2 : radius of circular disc - aPoint : center point coordinates (default (0,0,0)) - anAxis : unit vector in axis direction (default (0,0,1))", py::arg("R1"), py::arg("R2"), py::arg("aPoint"), py::arg("anAxisdir"));
	cls_IGESSolid_Torus.def("MajorRadius", (Standard_Real (IGESSolid_Torus::*)() const ) &IGESSolid_Torus::MajorRadius, "returns the distance from the center of torus to the center of the disc to be revolved");
	cls_IGESSolid_Torus.def("DiscRadius", (Standard_Real (IGESSolid_Torus::*)() const ) &IGESSolid_Torus::DiscRadius, "returns the radius of the disc to be revolved");
	cls_IGESSolid_Torus.def("AxisPoint", (gp_Pnt (IGESSolid_Torus::*)() const ) &IGESSolid_Torus::AxisPoint, "returns the center of torus");
	cls_IGESSolid_Torus.def("TransformedAxisPoint", (gp_Pnt (IGESSolid_Torus::*)() const ) &IGESSolid_Torus::TransformedAxisPoint, "returns the center of torus after applying TransformationMatrix");
	cls_IGESSolid_Torus.def("Axis", (gp_Dir (IGESSolid_Torus::*)() const ) &IGESSolid_Torus::Axis, "returns direction of the axis");
	cls_IGESSolid_Torus.def("TransformedAxis", (gp_Dir (IGESSolid_Torus::*)() const ) &IGESSolid_Torus::TransformedAxis, "returns direction of the axis after applying TransformationMatrix");
	cls_IGESSolid_Torus.def_static("get_type_name_", (const char * (*)()) &IGESSolid_Torus::get_type_name, "None");
	cls_IGESSolid_Torus.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_Torus::get_type_descriptor, "None");
	cls_IGESSolid_Torus.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_Torus::*)() const ) &IGESSolid_Torus::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_SolidOfRevolution.hxx
	py::class_<IGESSolid_SolidOfRevolution, opencascade::handle<IGESSolid_SolidOfRevolution>, IGESData_IGESEntity> cls_IGESSolid_SolidOfRevolution(mod, "IGESSolid_SolidOfRevolution", "defines SolidOfRevolution, Type <162> Form Number <0,1> in package IGESSolid This entity is defined by revolving the area determined by a planar curve about a specified axis through a given fraction of full rotation.");
	cls_IGESSolid_SolidOfRevolution.def(py::init<>());
	cls_IGESSolid_SolidOfRevolution.def("Init", (void (IGESSolid_SolidOfRevolution::*)(const opencascade::handle<IGESData_IGESEntity> &, const Standard_Real, const gp_XYZ &, const gp_XYZ &)) &IGESSolid_SolidOfRevolution::Init, "This method is used to set the fields of the class SolidOfRevolution - aCurve : the curve entity that is to be revolved - aFract : the fraction of full rotation (default 1.0) - aAxisPnt : the point on the axis - aDirection : the direction of the axis", py::arg("aCurve"), py::arg("aFract"), py::arg("aAxisPnt"), py::arg("aDirection"));
	cls_IGESSolid_SolidOfRevolution.def("SetClosedToAxis", (void (IGESSolid_SolidOfRevolution::*)(const Standard_Boolean)) &IGESSolid_SolidOfRevolution::SetClosedToAxis, "Sets the Curve to be by default, Closed to Axis (Form 0) if <mode> is True, Closed to Itself (Form 1) else", py::arg("mode"));
	cls_IGESSolid_SolidOfRevolution.def("IsClosedToAxis", (Standard_Boolean (IGESSolid_SolidOfRevolution::*)() const ) &IGESSolid_SolidOfRevolution::IsClosedToAxis, "Returns True if Form Number = 0 if Form no is 0, then the curve is closed to axis if 1, the curve is closed to itself.");
	cls_IGESSolid_SolidOfRevolution.def("Curve", (opencascade::handle<IGESData_IGESEntity> (IGESSolid_SolidOfRevolution::*)() const ) &IGESSolid_SolidOfRevolution::Curve, "returns the curve entity that is to be revolved");
	cls_IGESSolid_SolidOfRevolution.def("Fraction", (Standard_Real (IGESSolid_SolidOfRevolution::*)() const ) &IGESSolid_SolidOfRevolution::Fraction, "returns the fraction of full rotation that the curve is to be rotated");
	cls_IGESSolid_SolidOfRevolution.def("AxisPoint", (gp_Pnt (IGESSolid_SolidOfRevolution::*)() const ) &IGESSolid_SolidOfRevolution::AxisPoint, "returns the point on the axis");
	cls_IGESSolid_SolidOfRevolution.def("TransformedAxisPoint", (gp_Pnt (IGESSolid_SolidOfRevolution::*)() const ) &IGESSolid_SolidOfRevolution::TransformedAxisPoint, "returns the point on the axis after applying Trans.Matrix");
	cls_IGESSolid_SolidOfRevolution.def("Axis", (gp_Dir (IGESSolid_SolidOfRevolution::*)() const ) &IGESSolid_SolidOfRevolution::Axis, "returns the direction of the axis");
	cls_IGESSolid_SolidOfRevolution.def("TransformedAxis", (gp_Dir (IGESSolid_SolidOfRevolution::*)() const ) &IGESSolid_SolidOfRevolution::TransformedAxis, "returns the direction of the axis after applying TransformationMatrix");
	cls_IGESSolid_SolidOfRevolution.def_static("get_type_name_", (const char * (*)()) &IGESSolid_SolidOfRevolution::get_type_name, "None");
	cls_IGESSolid_SolidOfRevolution.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_SolidOfRevolution::get_type_descriptor, "None");
	cls_IGESSolid_SolidOfRevolution.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_SolidOfRevolution::*)() const ) &IGESSolid_SolidOfRevolution::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_SolidOfLinearExtrusion.hxx
	py::class_<IGESSolid_SolidOfLinearExtrusion, opencascade::handle<IGESSolid_SolidOfLinearExtrusion>, IGESData_IGESEntity> cls_IGESSolid_SolidOfLinearExtrusion(mod, "IGESSolid_SolidOfLinearExtrusion", "defines SolidOfLinearExtrusion, Type <164> Form Number <0> in package IGESSolid Solid of linear extrusion is defined by translatin an area determined by a planar curve");
	cls_IGESSolid_SolidOfLinearExtrusion.def(py::init<>());
	cls_IGESSolid_SolidOfLinearExtrusion.def("Init", (void (IGESSolid_SolidOfLinearExtrusion::*)(const opencascade::handle<IGESData_IGESEntity> &, const Standard_Real, const gp_XYZ &)) &IGESSolid_SolidOfLinearExtrusion::Init, "This method is used to set the fields of the class SolidOfLinearExtrusion - aCurve : the planar curve that is to be translated - aLength : the length of extrusion - aDirection : the vector specifying the direction of extrusion default (0,0,1)", py::arg("aCurve"), py::arg("aLength"), py::arg("aDirection"));
	cls_IGESSolid_SolidOfLinearExtrusion.def("Curve", (opencascade::handle<IGESData_IGESEntity> (IGESSolid_SolidOfLinearExtrusion::*)() const ) &IGESSolid_SolidOfLinearExtrusion::Curve, "returns the planar curve that is to be translated");
	cls_IGESSolid_SolidOfLinearExtrusion.def("ExtrusionLength", (Standard_Real (IGESSolid_SolidOfLinearExtrusion::*)() const ) &IGESSolid_SolidOfLinearExtrusion::ExtrusionLength, "returns the Extrusion Length");
	cls_IGESSolid_SolidOfLinearExtrusion.def("ExtrusionDirection", (gp_Dir (IGESSolid_SolidOfLinearExtrusion::*)() const ) &IGESSolid_SolidOfLinearExtrusion::ExtrusionDirection, "returns the Extrusion direction");
	cls_IGESSolid_SolidOfLinearExtrusion.def("TransformedExtrusionDirection", (gp_Dir (IGESSolid_SolidOfLinearExtrusion::*)() const ) &IGESSolid_SolidOfLinearExtrusion::TransformedExtrusionDirection, "returns ExtrusionDirection after applying TransformationMatrix");
	cls_IGESSolid_SolidOfLinearExtrusion.def_static("get_type_name_", (const char * (*)()) &IGESSolid_SolidOfLinearExtrusion::get_type_name, "None");
	cls_IGESSolid_SolidOfLinearExtrusion.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_SolidOfLinearExtrusion::get_type_descriptor, "None");
	cls_IGESSolid_SolidOfLinearExtrusion.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_SolidOfLinearExtrusion::*)() const ) &IGESSolid_SolidOfLinearExtrusion::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_Ellipsoid.hxx
	py::class_<IGESSolid_Ellipsoid, opencascade::handle<IGESSolid_Ellipsoid>, IGESData_IGESEntity> cls_IGESSolid_Ellipsoid(mod, "IGESSolid_Ellipsoid", "defines Ellipsoid, Type <168> Form Number <0> in package IGESSolid The ellipsoid is a solid bounded by the surface defined by: X^2 Y^2 Z^2 ----- + ----- + ----- = 1 LX^2 LY^2 LZ^2");
	cls_IGESSolid_Ellipsoid.def(py::init<>());
	cls_IGESSolid_Ellipsoid.def("Init", (void (IGESSolid_Ellipsoid::*)(const gp_XYZ &, const gp_XYZ &, const gp_XYZ &, const gp_XYZ &)) &IGESSolid_Ellipsoid::Init, "This method is used to set the fields of the class Ellipsoid - aSize : Lengths in the local X,Y,Z directions - aCenter : Center point of ellipsoid (default (0,0,0)) - anXAxis : Unit vector defining local X-axis default (1,0,0) - anZAxis : Unit vector defining local Z-axis default (0,0,1)", py::arg("aSize"), py::arg("aCenter"), py::arg("anXAxis"), py::arg("anZAxis"));
	cls_IGESSolid_Ellipsoid.def("Size", (gp_XYZ (IGESSolid_Ellipsoid::*)() const ) &IGESSolid_Ellipsoid::Size, "returns the size");
	cls_IGESSolid_Ellipsoid.def("XLength", (Standard_Real (IGESSolid_Ellipsoid::*)() const ) &IGESSolid_Ellipsoid::XLength, "returns the length in the local X-direction");
	cls_IGESSolid_Ellipsoid.def("YLength", (Standard_Real (IGESSolid_Ellipsoid::*)() const ) &IGESSolid_Ellipsoid::YLength, "returns the length in the local Y-direction");
	cls_IGESSolid_Ellipsoid.def("ZLength", (Standard_Real (IGESSolid_Ellipsoid::*)() const ) &IGESSolid_Ellipsoid::ZLength, "returns the length in the local Z-direction");
	cls_IGESSolid_Ellipsoid.def("Center", (gp_Pnt (IGESSolid_Ellipsoid::*)() const ) &IGESSolid_Ellipsoid::Center, "returns the center of the ellipsoid");
	cls_IGESSolid_Ellipsoid.def("TransformedCenter", (gp_Pnt (IGESSolid_Ellipsoid::*)() const ) &IGESSolid_Ellipsoid::TransformedCenter, "returns the center of the ellipsoid after applying TransformationMatrix");
	cls_IGESSolid_Ellipsoid.def("XAxis", (gp_Dir (IGESSolid_Ellipsoid::*)() const ) &IGESSolid_Ellipsoid::XAxis, "returns the vector corresponding to the local X-direction");
	cls_IGESSolid_Ellipsoid.def("TransformedXAxis", (gp_Dir (IGESSolid_Ellipsoid::*)() const ) &IGESSolid_Ellipsoid::TransformedXAxis, "returns the vector corresponding to the local X-direction after applying TransformationMatrix");
	cls_IGESSolid_Ellipsoid.def("YAxis", (gp_Dir (IGESSolid_Ellipsoid::*)() const ) &IGESSolid_Ellipsoid::YAxis, "returns the vector corresponding to the local Y-direction which is got by taking cross product of ZAxis and XAxis");
	cls_IGESSolid_Ellipsoid.def("TransformedYAxis", (gp_Dir (IGESSolid_Ellipsoid::*)() const ) &IGESSolid_Ellipsoid::TransformedYAxis, "returns the vector corresponding to the local Y-direction (which is got by taking cross product of ZAxis and XAxis) after applying TransformationMatrix");
	cls_IGESSolid_Ellipsoid.def("ZAxis", (gp_Dir (IGESSolid_Ellipsoid::*)() const ) &IGESSolid_Ellipsoid::ZAxis, "returns the vector corresponding to the local Z-direction");
	cls_IGESSolid_Ellipsoid.def("TransformedZAxis", (gp_Dir (IGESSolid_Ellipsoid::*)() const ) &IGESSolid_Ellipsoid::TransformedZAxis, "returns the vector corresponding to the local Z-direction after applying TransformationMatrix");
	cls_IGESSolid_Ellipsoid.def_static("get_type_name_", (const char * (*)()) &IGESSolid_Ellipsoid::get_type_name, "None");
	cls_IGESSolid_Ellipsoid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_Ellipsoid::get_type_descriptor, "None");
	cls_IGESSolid_Ellipsoid.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_Ellipsoid::*)() const ) &IGESSolid_Ellipsoid::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_BooleanTree.hxx
	py::class_<IGESSolid_BooleanTree, opencascade::handle<IGESSolid_BooleanTree>, IGESData_IGESEntity> cls_IGESSolid_BooleanTree(mod, "IGESSolid_BooleanTree", "defines BooleanTree, Type <180> Form Number <0> in package IGESSolid The Boolean tree describes a binary tree structure composed of regularized Boolean operations and operands, in post-order notation.");
	cls_IGESSolid_BooleanTree.def(py::init<>());
	cls_IGESSolid_BooleanTree.def("Init", (void (IGESSolid_BooleanTree::*)(const opencascade::handle<IGESData_HArray1OfIGESEntity> &, const opencascade::handle<TColStd_HArray1OfInteger> &)) &IGESSolid_BooleanTree::Init, "This method is used to set the fields of the class BooleanTree - operands : Array containing pointer to DE of operands - operations : Array containing integer type for operations", py::arg("operands"), py::arg("operations"));
	cls_IGESSolid_BooleanTree.def("Length", (Standard_Integer (IGESSolid_BooleanTree::*)() const ) &IGESSolid_BooleanTree::Length, "returns the length of the post-order list");
	cls_IGESSolid_BooleanTree.def("IsOperand", (Standard_Boolean (IGESSolid_BooleanTree::*)(const Standard_Integer) const ) &IGESSolid_BooleanTree::IsOperand, "returns True if Index'th value in the post-order list is an Operand; else returns False if it is an Integer Operations raises exception if Index < 1 or Index > Length()", py::arg("Index"));
	cls_IGESSolid_BooleanTree.def("Operand", (opencascade::handle<IGESData_IGESEntity> (IGESSolid_BooleanTree::*)(const Standard_Integer) const ) &IGESSolid_BooleanTree::Operand, "returns the Index'th value in the post-order list only if it is an operand else returns NULL raises exception if Index < 1 or Index > Length()", py::arg("Index"));
	cls_IGESSolid_BooleanTree.def("Operation", (Standard_Integer (IGESSolid_BooleanTree::*)(const Standard_Integer) const ) &IGESSolid_BooleanTree::Operation, "returns the Index'th value in the post-order list only if it is an operation else returns 0 raises exception if Index < 1 or Index > Length()", py::arg("Index"));
	cls_IGESSolid_BooleanTree.def_static("get_type_name_", (const char * (*)()) &IGESSolid_BooleanTree::get_type_name, "None");
	cls_IGESSolid_BooleanTree.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_BooleanTree::get_type_descriptor, "None");
	cls_IGESSolid_BooleanTree.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_BooleanTree::*)() const ) &IGESSolid_BooleanTree::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_SelectedComponent.hxx
	py::class_<IGESSolid_SelectedComponent, opencascade::handle<IGESSolid_SelectedComponent>, IGESData_IGESEntity> cls_IGESSolid_SelectedComponent(mod, "IGESSolid_SelectedComponent", "defines SelectedComponent, Type <182> Form Number <0> in package IGESSolid The Selected Component entity provides a means of selecting one component of a disjoint CSG solid");
	cls_IGESSolid_SelectedComponent.def(py::init<>());
	cls_IGESSolid_SelectedComponent.def("Init", (void (IGESSolid_SelectedComponent::*)(const opencascade::handle<IGESSolid_BooleanTree> &, const gp_XYZ &)) &IGESSolid_SelectedComponent::Init, "This method is used to set the fields of the class SelectedComponent - anEntity : the Boolean tree entity - selectPnt : Point in or on the desired component", py::arg("anEntity"), py::arg("selectPnt"));
	cls_IGESSolid_SelectedComponent.def("Component", (opencascade::handle<IGESSolid_BooleanTree> (IGESSolid_SelectedComponent::*)() const ) &IGESSolid_SelectedComponent::Component, "returns the Boolean tree entity");
	cls_IGESSolid_SelectedComponent.def("SelectPoint", (gp_Pnt (IGESSolid_SelectedComponent::*)() const ) &IGESSolid_SelectedComponent::SelectPoint, "returns the point on/in the selected component");
	cls_IGESSolid_SelectedComponent.def("TransformedSelectPoint", (gp_Pnt (IGESSolid_SelectedComponent::*)() const ) &IGESSolid_SelectedComponent::TransformedSelectPoint, "returns the point on/in the selected component after applying TransformationMatrix");
	cls_IGESSolid_SelectedComponent.def_static("get_type_name_", (const char * (*)()) &IGESSolid_SelectedComponent::get_type_name, "None");
	cls_IGESSolid_SelectedComponent.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_SelectedComponent::get_type_descriptor, "None");
	cls_IGESSolid_SelectedComponent.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_SelectedComponent::*)() const ) &IGESSolid_SelectedComponent::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_SolidAssembly.hxx
	py::class_<IGESSolid_SolidAssembly, opencascade::handle<IGESSolid_SolidAssembly>, IGESData_IGESEntity> cls_IGESSolid_SolidAssembly(mod, "IGESSolid_SolidAssembly", "defines SolidAssembly, Type <184> Form <0> in package IGESSolid Solid assembly is a collection of items which possess a shared fixed geometric relationship.");
	cls_IGESSolid_SolidAssembly.def(py::init<>());
	cls_IGESSolid_SolidAssembly.def("Init", (void (IGESSolid_SolidAssembly::*)(const opencascade::handle<IGESData_HArray1OfIGESEntity> &, const opencascade::handle<IGESGeom_HArray1OfTransformationMatrix> &)) &IGESSolid_SolidAssembly::Init, "This method is used to set the fields of the class SolidAssembly - allItems : the collection of items - allMatrices : transformation matrices corresponding to each item raises exception if the length of allItems & allMatrices do not match", py::arg("allItems"), py::arg("allMatrices"));
	cls_IGESSolid_SolidAssembly.def("HasBrep", (Standard_Boolean (IGESSolid_SolidAssembly::*)() const ) &IGESSolid_SolidAssembly::HasBrep, "Tells if at least one item is a Brep, from FormNumber");
	cls_IGESSolid_SolidAssembly.def("SetBrep", (void (IGESSolid_SolidAssembly::*)(const Standard_Boolean)) &IGESSolid_SolidAssembly::SetBrep, "Sets or Unsets the status 'HasBrep' from FormNumber Default is False", py::arg("hasbrep"));
	cls_IGESSolid_SolidAssembly.def("NbItems", (Standard_Integer (IGESSolid_SolidAssembly::*)() const ) &IGESSolid_SolidAssembly::NbItems, "returns the number of items in the collection");
	cls_IGESSolid_SolidAssembly.def("Item", (opencascade::handle<IGESData_IGESEntity> (IGESSolid_SolidAssembly::*)(const Standard_Integer) const ) &IGESSolid_SolidAssembly::Item, "returns the Index'th item raises exception if Index <= 0 or Index > NbItems()", py::arg("Index"));
	cls_IGESSolid_SolidAssembly.def("TransfMatrix", (opencascade::handle<IGESGeom_TransformationMatrix> (IGESSolid_SolidAssembly::*)(const Standard_Integer) const ) &IGESSolid_SolidAssembly::TransfMatrix, "returns the transformation matrix of the Index'th item raises exception if Index <= 0 or Index > NbItems()", py::arg("Index"));
	cls_IGESSolid_SolidAssembly.def_static("get_type_name_", (const char * (*)()) &IGESSolid_SolidAssembly::get_type_name, "None");
	cls_IGESSolid_SolidAssembly.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_SolidAssembly::get_type_descriptor, "None");
	cls_IGESSolid_SolidAssembly.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_SolidAssembly::*)() const ) &IGESSolid_SolidAssembly::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_PlaneSurface.hxx
	py::class_<IGESSolid_PlaneSurface, opencascade::handle<IGESSolid_PlaneSurface>, IGESData_IGESEntity> cls_IGESSolid_PlaneSurface(mod, "IGESSolid_PlaneSurface", "defines PlaneSurface, Type <190> Form Number <0,1> in package IGESSolid A plane surface entity is defined by a point on the surface and a normal to it.");
	cls_IGESSolid_PlaneSurface.def(py::init<>());
	cls_IGESSolid_PlaneSurface.def("Init", (void (IGESSolid_PlaneSurface::*)(const opencascade::handle<IGESGeom_Point> &, const opencascade::handle<IGESGeom_Direction> &, const opencascade::handle<IGESGeom_Direction> &)) &IGESSolid_PlaneSurface::Init, "This method is used to set the fields of the class PlaneSurface - aLocation : the point on the surface - aNormal : the surface normal direction - refdir : the reference direction (default NULL) for unparameterised curves", py::arg("aLocation"), py::arg("aNormal"), py::arg("refdir"));
	cls_IGESSolid_PlaneSurface.def("LocationPoint", (opencascade::handle<IGESGeom_Point> (IGESSolid_PlaneSurface::*)() const ) &IGESSolid_PlaneSurface::LocationPoint, "returns the point on the surface");
	cls_IGESSolid_PlaneSurface.def("Normal", (opencascade::handle<IGESGeom_Direction> (IGESSolid_PlaneSurface::*)() const ) &IGESSolid_PlaneSurface::Normal, "returns the normal to the surface");
	cls_IGESSolid_PlaneSurface.def("ReferenceDir", (opencascade::handle<IGESGeom_Direction> (IGESSolid_PlaneSurface::*)() const ) &IGESSolid_PlaneSurface::ReferenceDir, "returns the reference direction (for parameterised curve) returns NULL for unparameterised curve");
	cls_IGESSolid_PlaneSurface.def("IsParametrised", (Standard_Boolean (IGESSolid_PlaneSurface::*)() const ) &IGESSolid_PlaneSurface::IsParametrised, "returns True if parameterised, else False");
	cls_IGESSolid_PlaneSurface.def_static("get_type_name_", (const char * (*)()) &IGESSolid_PlaneSurface::get_type_name, "None");
	cls_IGESSolid_PlaneSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_PlaneSurface::get_type_descriptor, "None");
	cls_IGESSolid_PlaneSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_PlaneSurface::*)() const ) &IGESSolid_PlaneSurface::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_CylindricalSurface.hxx
	py::class_<IGESSolid_CylindricalSurface, opencascade::handle<IGESSolid_CylindricalSurface>, IGESData_IGESEntity> cls_IGESSolid_CylindricalSurface(mod, "IGESSolid_CylindricalSurface", "defines CylindricalSurface, Type <192> Form Number <0,1> in package IGESSolid");
	cls_IGESSolid_CylindricalSurface.def(py::init<>());
	cls_IGESSolid_CylindricalSurface.def("Init", (void (IGESSolid_CylindricalSurface::*)(const opencascade::handle<IGESGeom_Point> &, const opencascade::handle<IGESGeom_Direction> &, const Standard_Real, const opencascade::handle<IGESGeom_Direction> &)) &IGESSolid_CylindricalSurface::Init, "This method is used to set the fields of the class CylindricalSurface - aLocation : the location of the point on axis - anAxis : the direction of the axis - aRadius : the radius at the axis point - aRefdir : the reference direction (parametrised surface) default NULL (unparametrised surface)", py::arg("aLocation"), py::arg("anAxis"), py::arg("aRadius"), py::arg("aRefdir"));
	cls_IGESSolid_CylindricalSurface.def("LocationPoint", (opencascade::handle<IGESGeom_Point> (IGESSolid_CylindricalSurface::*)() const ) &IGESSolid_CylindricalSurface::LocationPoint, "returns the point on the axis");
	cls_IGESSolid_CylindricalSurface.def("Axis", (opencascade::handle<IGESGeom_Direction> (IGESSolid_CylindricalSurface::*)() const ) &IGESSolid_CylindricalSurface::Axis, "returns the direction on the axis");
	cls_IGESSolid_CylindricalSurface.def("Radius", (Standard_Real (IGESSolid_CylindricalSurface::*)() const ) &IGESSolid_CylindricalSurface::Radius, "returns the radius at the axis point");
	cls_IGESSolid_CylindricalSurface.def("IsParametrised", (Standard_Boolean (IGESSolid_CylindricalSurface::*)() const ) &IGESSolid_CylindricalSurface::IsParametrised, "returns whether the surface is parametrised or not");
	cls_IGESSolid_CylindricalSurface.def("ReferenceDir", (opencascade::handle<IGESGeom_Direction> (IGESSolid_CylindricalSurface::*)() const ) &IGESSolid_CylindricalSurface::ReferenceDir, "returns the reference direction only for parametrised surface else returns NULL");
	cls_IGESSolid_CylindricalSurface.def_static("get_type_name_", (const char * (*)()) &IGESSolid_CylindricalSurface::get_type_name, "None");
	cls_IGESSolid_CylindricalSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_CylindricalSurface::get_type_descriptor, "None");
	cls_IGESSolid_CylindricalSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_CylindricalSurface::*)() const ) &IGESSolid_CylindricalSurface::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_ConicalSurface.hxx
	py::class_<IGESSolid_ConicalSurface, opencascade::handle<IGESSolid_ConicalSurface>, IGESData_IGESEntity> cls_IGESSolid_ConicalSurface(mod, "IGESSolid_ConicalSurface", "defines ConicalSurface, Type <194> Form Number <0,1> in package IGESSolid The right circular conical surface is defined by a point on the axis on the cone, the direction of the axis of the cone, the radius of the cone at the axis point and the cone semi-angle.");
	cls_IGESSolid_ConicalSurface.def(py::init<>());
	cls_IGESSolid_ConicalSurface.def("Init", (void (IGESSolid_ConicalSurface::*)(const opencascade::handle<IGESGeom_Point> &, const opencascade::handle<IGESGeom_Direction> &, const Standard_Real, const Standard_Real, const opencascade::handle<IGESGeom_Direction> &)) &IGESSolid_ConicalSurface::Init, "This method is used to set the fields of the class ConicalSurface - aLocation : Location of the point on axis - anAxis : Direction of the axis - aRadius : Radius at axis point - anAngle : Value of semi-angle in degrees (0<angle<90) - aRefdir : Reference direction (parametrised surface) Null if unparametrised surface.", py::arg("aLocation"), py::arg("anAxis"), py::arg("aRadius"), py::arg("anAngle"), py::arg("aRefdir"));
	cls_IGESSolid_ConicalSurface.def("LocationPoint", (opencascade::handle<IGESGeom_Point> (IGESSolid_ConicalSurface::*)() const ) &IGESSolid_ConicalSurface::LocationPoint, "returns the location of the point on the axis");
	cls_IGESSolid_ConicalSurface.def("Axis", (opencascade::handle<IGESGeom_Direction> (IGESSolid_ConicalSurface::*)() const ) &IGESSolid_ConicalSurface::Axis, "returns the direction of the axis");
	cls_IGESSolid_ConicalSurface.def("Radius", (Standard_Real (IGESSolid_ConicalSurface::*)() const ) &IGESSolid_ConicalSurface::Radius, "returns the radius at the axis point");
	cls_IGESSolid_ConicalSurface.def("SemiAngle", (Standard_Real (IGESSolid_ConicalSurface::*)() const ) &IGESSolid_ConicalSurface::SemiAngle, "returns the semi-angle value");
	cls_IGESSolid_ConicalSurface.def("ReferenceDir", (opencascade::handle<IGESGeom_Direction> (IGESSolid_ConicalSurface::*)() const ) &IGESSolid_ConicalSurface::ReferenceDir, "returns the reference direction of the conical surface in case of parametrised surface. For unparametrised surface it returns NULL.");
	cls_IGESSolid_ConicalSurface.def("IsParametrised", (Standard_Boolean (IGESSolid_ConicalSurface::*)() const ) &IGESSolid_ConicalSurface::IsParametrised, "returns True if Form no is 1 else false");
	cls_IGESSolid_ConicalSurface.def_static("get_type_name_", (const char * (*)()) &IGESSolid_ConicalSurface::get_type_name, "None");
	cls_IGESSolid_ConicalSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_ConicalSurface::get_type_descriptor, "None");
	cls_IGESSolid_ConicalSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_ConicalSurface::*)() const ) &IGESSolid_ConicalSurface::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_SphericalSurface.hxx
	py::class_<IGESSolid_SphericalSurface, opencascade::handle<IGESSolid_SphericalSurface>, IGESData_IGESEntity> cls_IGESSolid_SphericalSurface(mod, "IGESSolid_SphericalSurface", "defines SphericalSurface, Type <196> Form Number <0,1> in package IGESSolid Spherical surface is defined by a center and radius. In case of parametrised surface an axis and a reference direction is provided.");
	cls_IGESSolid_SphericalSurface.def(py::init<>());
	cls_IGESSolid_SphericalSurface.def("Init", (void (IGESSolid_SphericalSurface::*)(const opencascade::handle<IGESGeom_Point> &, const Standard_Real, const opencascade::handle<IGESGeom_Direction> &, const opencascade::handle<IGESGeom_Direction> &)) &IGESSolid_SphericalSurface::Init, "This method is used to set the fields of the class SphericalSurface - aCenter : the coordinates of the center point - aRadius : value of radius - anAxis : the direction of the axis Null in case of Unparametrised surface - aRefdir : the reference direction Null in case of Unparametrised surface", py::arg("aCenter"), py::arg("aRadius"), py::arg("anAxis"), py::arg("aRefdir"));
	cls_IGESSolid_SphericalSurface.def("Center", (opencascade::handle<IGESGeom_Point> (IGESSolid_SphericalSurface::*)() const ) &IGESSolid_SphericalSurface::Center, "returns the center of the spherical surface");
	cls_IGESSolid_SphericalSurface.def("TransformedCenter", (gp_Pnt (IGESSolid_SphericalSurface::*)() const ) &IGESSolid_SphericalSurface::TransformedCenter, "returns the center of the spherical surface after applying TransformationMatrix");
	cls_IGESSolid_SphericalSurface.def("Radius", (Standard_Real (IGESSolid_SphericalSurface::*)() const ) &IGESSolid_SphericalSurface::Radius, "returns the radius of the spherical surface");
	cls_IGESSolid_SphericalSurface.def("Axis", (opencascade::handle<IGESGeom_Direction> (IGESSolid_SphericalSurface::*)() const ) &IGESSolid_SphericalSurface::Axis, "returns the direction of the axis (Parametrised surface) Null is returned if the surface is not parametrised");
	cls_IGESSolid_SphericalSurface.def("ReferenceDir", (opencascade::handle<IGESGeom_Direction> (IGESSolid_SphericalSurface::*)() const ) &IGESSolid_SphericalSurface::ReferenceDir, "returns the reference direction (Parametrised surface) Null is returned if the surface is not parametrised");
	cls_IGESSolid_SphericalSurface.def("IsParametrised", (Standard_Boolean (IGESSolid_SphericalSurface::*)() const ) &IGESSolid_SphericalSurface::IsParametrised, "Returns True if the surface is parametrised, else False");
	cls_IGESSolid_SphericalSurface.def_static("get_type_name_", (const char * (*)()) &IGESSolid_SphericalSurface::get_type_name, "None");
	cls_IGESSolid_SphericalSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_SphericalSurface::get_type_descriptor, "None");
	cls_IGESSolid_SphericalSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_SphericalSurface::*)() const ) &IGESSolid_SphericalSurface::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_ToroidalSurface.hxx
	py::class_<IGESSolid_ToroidalSurface, opencascade::handle<IGESSolid_ToroidalSurface>, IGESData_IGESEntity> cls_IGESSolid_ToroidalSurface(mod, "IGESSolid_ToroidalSurface", "defines ToroidalSurface, Type <198> Form Number <0,1> in package IGESSolid This entity is defined by the center point, the axis direction and the major and minor radii. In case of parametrised surface a reference direction is provided.");
	cls_IGESSolid_ToroidalSurface.def(py::init<>());
	cls_IGESSolid_ToroidalSurface.def("Init", (void (IGESSolid_ToroidalSurface::*)(const opencascade::handle<IGESGeom_Point> &, const opencascade::handle<IGESGeom_Direction> &, const Standard_Real, const Standard_Real, const opencascade::handle<IGESGeom_Direction> &)) &IGESSolid_ToroidalSurface::Init, "This method is used to set the fields of the class ToroidalSurface - aCenter : the center point coordinates - anAxis : the direction of the axis - majRadius : the major radius - minRadius : the minor radius - Refdir : the reference direction (parametrised) default Null for unparametrised surface", py::arg("aCenter"), py::arg("anAxis"), py::arg("majRadius"), py::arg("minRadius"), py::arg("Refdir"));
	cls_IGESSolid_ToroidalSurface.def("Center", (opencascade::handle<IGESGeom_Point> (IGESSolid_ToroidalSurface::*)() const ) &IGESSolid_ToroidalSurface::Center, "returns the center point coordinates of the surface");
	cls_IGESSolid_ToroidalSurface.def("TransformedCenter", (gp_Pnt (IGESSolid_ToroidalSurface::*)() const ) &IGESSolid_ToroidalSurface::TransformedCenter, "returns the center point coordinates of the surface after applying TransformationMatrix");
	cls_IGESSolid_ToroidalSurface.def("Axis", (opencascade::handle<IGESGeom_Direction> (IGESSolid_ToroidalSurface::*)() const ) &IGESSolid_ToroidalSurface::Axis, "returns the direction of the axis");
	cls_IGESSolid_ToroidalSurface.def("MajorRadius", (Standard_Real (IGESSolid_ToroidalSurface::*)() const ) &IGESSolid_ToroidalSurface::MajorRadius, "returns the major radius of the surface");
	cls_IGESSolid_ToroidalSurface.def("MinorRadius", (Standard_Real (IGESSolid_ToroidalSurface::*)() const ) &IGESSolid_ToroidalSurface::MinorRadius, "returns the minor radius of the surface");
	cls_IGESSolid_ToroidalSurface.def("ReferenceDir", (opencascade::handle<IGESGeom_Direction> (IGESSolid_ToroidalSurface::*)() const ) &IGESSolid_ToroidalSurface::ReferenceDir, "returns the reference direction (parametrised surface) Null is returned if the surface is not parametrised");
	cls_IGESSolid_ToroidalSurface.def("IsParametrised", (Standard_Boolean (IGESSolid_ToroidalSurface::*)() const ) &IGESSolid_ToroidalSurface::IsParametrised, "Returns True if the surface is parametrised, else False");
	cls_IGESSolid_ToroidalSurface.def_static("get_type_name_", (const char * (*)()) &IGESSolid_ToroidalSurface::get_type_name, "None");
	cls_IGESSolid_ToroidalSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_ToroidalSurface::get_type_descriptor, "None");
	cls_IGESSolid_ToroidalSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_ToroidalSurface::*)() const ) &IGESSolid_ToroidalSurface::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_SolidInstance.hxx
	py::class_<IGESSolid_SolidInstance, opencascade::handle<IGESSolid_SolidInstance>, IGESData_IGESEntity> cls_IGESSolid_SolidInstance(mod, "IGESSolid_SolidInstance", "defines SolidInstance, Type <430> Form Number <0> in package IGESSolid This provides a mechanism for replicating a solid representation.");
	cls_IGESSolid_SolidInstance.def(py::init<>());
	cls_IGESSolid_SolidInstance.def("Init", (void (IGESSolid_SolidInstance::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESSolid_SolidInstance::Init, "This method is used to set the fields of the class SolidInstance - anEntity : the entity corresponding to the solid", py::arg("anEntity"));
	cls_IGESSolid_SolidInstance.def("IsBrep", (Standard_Boolean (IGESSolid_SolidInstance::*)() const ) &IGESSolid_SolidInstance::IsBrep, "Tells if a SolidInstance is for a BREP Default is False");
	cls_IGESSolid_SolidInstance.def("SetBrep", (void (IGESSolid_SolidInstance::*)(const Standard_Boolean)) &IGESSolid_SolidInstance::SetBrep, "Sets or unsets the Brep status (FormNumber = 1 else 0)", py::arg("brep"));
	cls_IGESSolid_SolidInstance.def("Entity", (opencascade::handle<IGESData_IGESEntity> (IGESSolid_SolidInstance::*)() const ) &IGESSolid_SolidInstance::Entity, "returns the solid entity");
	cls_IGESSolid_SolidInstance.def_static("get_type_name_", (const char * (*)()) &IGESSolid_SolidInstance::get_type_name, "None");
	cls_IGESSolid_SolidInstance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_SolidInstance::get_type_descriptor, "None");
	cls_IGESSolid_SolidInstance.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_SolidInstance::*)() const ) &IGESSolid_SolidInstance::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_ToolBlock.hxx
	py::class_<IGESSolid_ToolBlock, std::unique_ptr<IGESSolid_ToolBlock, Deleter<IGESSolid_ToolBlock>>> cls_IGESSolid_ToolBlock(mod, "IGESSolid_ToolBlock", "Tool to work on a Block. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESSolid_ToolBlock.def(py::init<>());
	cls_IGESSolid_ToolBlock.def("ReadOwnParams", (void (IGESSolid_ToolBlock::*)(const opencascade::handle<IGESSolid_Block> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESSolid_ToolBlock::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESSolid_ToolBlock.def("WriteOwnParams", (void (IGESSolid_ToolBlock::*)(const opencascade::handle<IGESSolid_Block> &, IGESData_IGESWriter &) const ) &IGESSolid_ToolBlock::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESSolid_ToolBlock.def("OwnShared", (void (IGESSolid_ToolBlock::*)(const opencascade::handle<IGESSolid_Block> &, Interface_EntityIterator &) const ) &IGESSolid_ToolBlock::OwnShared, "Lists the Entities shared by a Block <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESSolid_ToolBlock.def("DirChecker", (IGESData_DirChecker (IGESSolid_ToolBlock::*)(const opencascade::handle<IGESSolid_Block> &) const ) &IGESSolid_ToolBlock::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESSolid_ToolBlock.def("OwnCheck", (void (IGESSolid_ToolBlock::*)(const opencascade::handle<IGESSolid_Block> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESSolid_ToolBlock::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESSolid_ToolBlock.def("OwnCopy", (void (IGESSolid_ToolBlock::*)(const opencascade::handle<IGESSolid_Block> &, const opencascade::handle<IGESSolid_Block> &, Interface_CopyTool &) const ) &IGESSolid_ToolBlock::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESSolid_ToolBlock.def("OwnDump", (void (IGESSolid_ToolBlock::*)(const opencascade::handle<IGESSolid_Block> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESSolid_ToolBlock::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_ToolRightAngularWedge.hxx
	py::class_<IGESSolid_ToolRightAngularWedge, std::unique_ptr<IGESSolid_ToolRightAngularWedge, Deleter<IGESSolid_ToolRightAngularWedge>>> cls_IGESSolid_ToolRightAngularWedge(mod, "IGESSolid_ToolRightAngularWedge", "Tool to work on a RightAngularWedge. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESSolid_ToolRightAngularWedge.def(py::init<>());
	cls_IGESSolid_ToolRightAngularWedge.def("ReadOwnParams", (void (IGESSolid_ToolRightAngularWedge::*)(const opencascade::handle<IGESSolid_RightAngularWedge> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESSolid_ToolRightAngularWedge::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESSolid_ToolRightAngularWedge.def("WriteOwnParams", (void (IGESSolid_ToolRightAngularWedge::*)(const opencascade::handle<IGESSolid_RightAngularWedge> &, IGESData_IGESWriter &) const ) &IGESSolid_ToolRightAngularWedge::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESSolid_ToolRightAngularWedge.def("OwnShared", (void (IGESSolid_ToolRightAngularWedge::*)(const opencascade::handle<IGESSolid_RightAngularWedge> &, Interface_EntityIterator &) const ) &IGESSolid_ToolRightAngularWedge::OwnShared, "Lists the Entities shared by a RightAngularWedge <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESSolid_ToolRightAngularWedge.def("DirChecker", (IGESData_DirChecker (IGESSolid_ToolRightAngularWedge::*)(const opencascade::handle<IGESSolid_RightAngularWedge> &) const ) &IGESSolid_ToolRightAngularWedge::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESSolid_ToolRightAngularWedge.def("OwnCheck", (void (IGESSolid_ToolRightAngularWedge::*)(const opencascade::handle<IGESSolid_RightAngularWedge> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESSolid_ToolRightAngularWedge::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESSolid_ToolRightAngularWedge.def("OwnCopy", (void (IGESSolid_ToolRightAngularWedge::*)(const opencascade::handle<IGESSolid_RightAngularWedge> &, const opencascade::handle<IGESSolid_RightAngularWedge> &, Interface_CopyTool &) const ) &IGESSolid_ToolRightAngularWedge::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESSolid_ToolRightAngularWedge.def("OwnDump", (void (IGESSolid_ToolRightAngularWedge::*)(const opencascade::handle<IGESSolid_RightAngularWedge> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESSolid_ToolRightAngularWedge::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_ToolCylinder.hxx
	py::class_<IGESSolid_ToolCylinder, std::unique_ptr<IGESSolid_ToolCylinder, Deleter<IGESSolid_ToolCylinder>>> cls_IGESSolid_ToolCylinder(mod, "IGESSolid_ToolCylinder", "Tool to work on a Cylinder. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESSolid_ToolCylinder.def(py::init<>());
	cls_IGESSolid_ToolCylinder.def("ReadOwnParams", (void (IGESSolid_ToolCylinder::*)(const opencascade::handle<IGESSolid_Cylinder> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESSolid_ToolCylinder::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESSolid_ToolCylinder.def("WriteOwnParams", (void (IGESSolid_ToolCylinder::*)(const opencascade::handle<IGESSolid_Cylinder> &, IGESData_IGESWriter &) const ) &IGESSolid_ToolCylinder::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESSolid_ToolCylinder.def("OwnShared", (void (IGESSolid_ToolCylinder::*)(const opencascade::handle<IGESSolid_Cylinder> &, Interface_EntityIterator &) const ) &IGESSolid_ToolCylinder::OwnShared, "Lists the Entities shared by a Cylinder <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESSolid_ToolCylinder.def("DirChecker", (IGESData_DirChecker (IGESSolid_ToolCylinder::*)(const opencascade::handle<IGESSolid_Cylinder> &) const ) &IGESSolid_ToolCylinder::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESSolid_ToolCylinder.def("OwnCheck", (void (IGESSolid_ToolCylinder::*)(const opencascade::handle<IGESSolid_Cylinder> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESSolid_ToolCylinder::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESSolid_ToolCylinder.def("OwnCopy", (void (IGESSolid_ToolCylinder::*)(const opencascade::handle<IGESSolid_Cylinder> &, const opencascade::handle<IGESSolid_Cylinder> &, Interface_CopyTool &) const ) &IGESSolid_ToolCylinder::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESSolid_ToolCylinder.def("OwnDump", (void (IGESSolid_ToolCylinder::*)(const opencascade::handle<IGESSolid_Cylinder> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESSolid_ToolCylinder::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_ToolConeFrustum.hxx
	py::class_<IGESSolid_ToolConeFrustum, std::unique_ptr<IGESSolid_ToolConeFrustum, Deleter<IGESSolid_ToolConeFrustum>>> cls_IGESSolid_ToolConeFrustum(mod, "IGESSolid_ToolConeFrustum", "Tool to work on a ConeFrustum. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESSolid_ToolConeFrustum.def(py::init<>());
	cls_IGESSolid_ToolConeFrustum.def("ReadOwnParams", (void (IGESSolid_ToolConeFrustum::*)(const opencascade::handle<IGESSolid_ConeFrustum> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESSolid_ToolConeFrustum::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESSolid_ToolConeFrustum.def("WriteOwnParams", (void (IGESSolid_ToolConeFrustum::*)(const opencascade::handle<IGESSolid_ConeFrustum> &, IGESData_IGESWriter &) const ) &IGESSolid_ToolConeFrustum::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESSolid_ToolConeFrustum.def("OwnShared", (void (IGESSolid_ToolConeFrustum::*)(const opencascade::handle<IGESSolid_ConeFrustum> &, Interface_EntityIterator &) const ) &IGESSolid_ToolConeFrustum::OwnShared, "Lists the Entities shared by a ConeFrustum <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESSolid_ToolConeFrustum.def("DirChecker", (IGESData_DirChecker (IGESSolid_ToolConeFrustum::*)(const opencascade::handle<IGESSolid_ConeFrustum> &) const ) &IGESSolid_ToolConeFrustum::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESSolid_ToolConeFrustum.def("OwnCheck", (void (IGESSolid_ToolConeFrustum::*)(const opencascade::handle<IGESSolid_ConeFrustum> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESSolid_ToolConeFrustum::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESSolid_ToolConeFrustum.def("OwnCopy", (void (IGESSolid_ToolConeFrustum::*)(const opencascade::handle<IGESSolid_ConeFrustum> &, const opencascade::handle<IGESSolid_ConeFrustum> &, Interface_CopyTool &) const ) &IGESSolid_ToolConeFrustum::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESSolid_ToolConeFrustum.def("OwnDump", (void (IGESSolid_ToolConeFrustum::*)(const opencascade::handle<IGESSolid_ConeFrustum> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESSolid_ToolConeFrustum::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_ToolSphere.hxx
	py::class_<IGESSolid_ToolSphere, std::unique_ptr<IGESSolid_ToolSphere, Deleter<IGESSolid_ToolSphere>>> cls_IGESSolid_ToolSphere(mod, "IGESSolid_ToolSphere", "Tool to work on a Sphere. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESSolid_ToolSphere.def(py::init<>());
	cls_IGESSolid_ToolSphere.def("ReadOwnParams", (void (IGESSolid_ToolSphere::*)(const opencascade::handle<IGESSolid_Sphere> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESSolid_ToolSphere::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESSolid_ToolSphere.def("WriteOwnParams", (void (IGESSolid_ToolSphere::*)(const opencascade::handle<IGESSolid_Sphere> &, IGESData_IGESWriter &) const ) &IGESSolid_ToolSphere::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESSolid_ToolSphere.def("OwnShared", (void (IGESSolid_ToolSphere::*)(const opencascade::handle<IGESSolid_Sphere> &, Interface_EntityIterator &) const ) &IGESSolid_ToolSphere::OwnShared, "Lists the Entities shared by a Sphere <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESSolid_ToolSphere.def("DirChecker", (IGESData_DirChecker (IGESSolid_ToolSphere::*)(const opencascade::handle<IGESSolid_Sphere> &) const ) &IGESSolid_ToolSphere::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESSolid_ToolSphere.def("OwnCheck", (void (IGESSolid_ToolSphere::*)(const opencascade::handle<IGESSolid_Sphere> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESSolid_ToolSphere::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESSolid_ToolSphere.def("OwnCopy", (void (IGESSolid_ToolSphere::*)(const opencascade::handle<IGESSolid_Sphere> &, const opencascade::handle<IGESSolid_Sphere> &, Interface_CopyTool &) const ) &IGESSolid_ToolSphere::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESSolid_ToolSphere.def("OwnDump", (void (IGESSolid_ToolSphere::*)(const opencascade::handle<IGESSolid_Sphere> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESSolid_ToolSphere::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_ToolTorus.hxx
	py::class_<IGESSolid_ToolTorus, std::unique_ptr<IGESSolid_ToolTorus, Deleter<IGESSolid_ToolTorus>>> cls_IGESSolid_ToolTorus(mod, "IGESSolid_ToolTorus", "Tool to work on a Torus. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESSolid_ToolTorus.def(py::init<>());
	cls_IGESSolid_ToolTorus.def("ReadOwnParams", (void (IGESSolid_ToolTorus::*)(const opencascade::handle<IGESSolid_Torus> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESSolid_ToolTorus::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESSolid_ToolTorus.def("WriteOwnParams", (void (IGESSolid_ToolTorus::*)(const opencascade::handle<IGESSolid_Torus> &, IGESData_IGESWriter &) const ) &IGESSolid_ToolTorus::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESSolid_ToolTorus.def("OwnShared", (void (IGESSolid_ToolTorus::*)(const opencascade::handle<IGESSolid_Torus> &, Interface_EntityIterator &) const ) &IGESSolid_ToolTorus::OwnShared, "Lists the Entities shared by a Torus <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESSolid_ToolTorus.def("DirChecker", (IGESData_DirChecker (IGESSolid_ToolTorus::*)(const opencascade::handle<IGESSolid_Torus> &) const ) &IGESSolid_ToolTorus::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESSolid_ToolTorus.def("OwnCheck", (void (IGESSolid_ToolTorus::*)(const opencascade::handle<IGESSolid_Torus> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESSolid_ToolTorus::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESSolid_ToolTorus.def("OwnCopy", (void (IGESSolid_ToolTorus::*)(const opencascade::handle<IGESSolid_Torus> &, const opencascade::handle<IGESSolid_Torus> &, Interface_CopyTool &) const ) &IGESSolid_ToolTorus::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESSolid_ToolTorus.def("OwnDump", (void (IGESSolid_ToolTorus::*)(const opencascade::handle<IGESSolid_Torus> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESSolid_ToolTorus::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_ToolSolidOfRevolution.hxx
	py::class_<IGESSolid_ToolSolidOfRevolution, std::unique_ptr<IGESSolid_ToolSolidOfRevolution, Deleter<IGESSolid_ToolSolidOfRevolution>>> cls_IGESSolid_ToolSolidOfRevolution(mod, "IGESSolid_ToolSolidOfRevolution", "Tool to work on a SolidOfRevolution. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESSolid_ToolSolidOfRevolution.def(py::init<>());
	cls_IGESSolid_ToolSolidOfRevolution.def("ReadOwnParams", (void (IGESSolid_ToolSolidOfRevolution::*)(const opencascade::handle<IGESSolid_SolidOfRevolution> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESSolid_ToolSolidOfRevolution::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESSolid_ToolSolidOfRevolution.def("WriteOwnParams", (void (IGESSolid_ToolSolidOfRevolution::*)(const opencascade::handle<IGESSolid_SolidOfRevolution> &, IGESData_IGESWriter &) const ) &IGESSolid_ToolSolidOfRevolution::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESSolid_ToolSolidOfRevolution.def("OwnShared", (void (IGESSolid_ToolSolidOfRevolution::*)(const opencascade::handle<IGESSolid_SolidOfRevolution> &, Interface_EntityIterator &) const ) &IGESSolid_ToolSolidOfRevolution::OwnShared, "Lists the Entities shared by a SolidOfRevolution <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESSolid_ToolSolidOfRevolution.def("DirChecker", (IGESData_DirChecker (IGESSolid_ToolSolidOfRevolution::*)(const opencascade::handle<IGESSolid_SolidOfRevolution> &) const ) &IGESSolid_ToolSolidOfRevolution::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESSolid_ToolSolidOfRevolution.def("OwnCheck", (void (IGESSolid_ToolSolidOfRevolution::*)(const opencascade::handle<IGESSolid_SolidOfRevolution> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESSolid_ToolSolidOfRevolution::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESSolid_ToolSolidOfRevolution.def("OwnCopy", (void (IGESSolid_ToolSolidOfRevolution::*)(const opencascade::handle<IGESSolid_SolidOfRevolution> &, const opencascade::handle<IGESSolid_SolidOfRevolution> &, Interface_CopyTool &) const ) &IGESSolid_ToolSolidOfRevolution::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESSolid_ToolSolidOfRevolution.def("OwnDump", (void (IGESSolid_ToolSolidOfRevolution::*)(const opencascade::handle<IGESSolid_SolidOfRevolution> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESSolid_ToolSolidOfRevolution::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_ToolSolidOfLinearExtrusion.hxx
	py::class_<IGESSolid_ToolSolidOfLinearExtrusion, std::unique_ptr<IGESSolid_ToolSolidOfLinearExtrusion, Deleter<IGESSolid_ToolSolidOfLinearExtrusion>>> cls_IGESSolid_ToolSolidOfLinearExtrusion(mod, "IGESSolid_ToolSolidOfLinearExtrusion", "Tool to work on a SolidOfLinearExtrusion. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESSolid_ToolSolidOfLinearExtrusion.def(py::init<>());
	cls_IGESSolid_ToolSolidOfLinearExtrusion.def("ReadOwnParams", (void (IGESSolid_ToolSolidOfLinearExtrusion::*)(const opencascade::handle<IGESSolid_SolidOfLinearExtrusion> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESSolid_ToolSolidOfLinearExtrusion::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESSolid_ToolSolidOfLinearExtrusion.def("WriteOwnParams", (void (IGESSolid_ToolSolidOfLinearExtrusion::*)(const opencascade::handle<IGESSolid_SolidOfLinearExtrusion> &, IGESData_IGESWriter &) const ) &IGESSolid_ToolSolidOfLinearExtrusion::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESSolid_ToolSolidOfLinearExtrusion.def("OwnShared", (void (IGESSolid_ToolSolidOfLinearExtrusion::*)(const opencascade::handle<IGESSolid_SolidOfLinearExtrusion> &, Interface_EntityIterator &) const ) &IGESSolid_ToolSolidOfLinearExtrusion::OwnShared, "Lists the Entities shared by a SolidOfLinearExtrusion <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESSolid_ToolSolidOfLinearExtrusion.def("DirChecker", (IGESData_DirChecker (IGESSolid_ToolSolidOfLinearExtrusion::*)(const opencascade::handle<IGESSolid_SolidOfLinearExtrusion> &) const ) &IGESSolid_ToolSolidOfLinearExtrusion::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESSolid_ToolSolidOfLinearExtrusion.def("OwnCheck", (void (IGESSolid_ToolSolidOfLinearExtrusion::*)(const opencascade::handle<IGESSolid_SolidOfLinearExtrusion> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESSolid_ToolSolidOfLinearExtrusion::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESSolid_ToolSolidOfLinearExtrusion.def("OwnCopy", (void (IGESSolid_ToolSolidOfLinearExtrusion::*)(const opencascade::handle<IGESSolid_SolidOfLinearExtrusion> &, const opencascade::handle<IGESSolid_SolidOfLinearExtrusion> &, Interface_CopyTool &) const ) &IGESSolid_ToolSolidOfLinearExtrusion::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESSolid_ToolSolidOfLinearExtrusion.def("OwnDump", (void (IGESSolid_ToolSolidOfLinearExtrusion::*)(const opencascade::handle<IGESSolid_SolidOfLinearExtrusion> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESSolid_ToolSolidOfLinearExtrusion::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_ToolEllipsoid.hxx
	py::class_<IGESSolid_ToolEllipsoid, std::unique_ptr<IGESSolid_ToolEllipsoid, Deleter<IGESSolid_ToolEllipsoid>>> cls_IGESSolid_ToolEllipsoid(mod, "IGESSolid_ToolEllipsoid", "Tool to work on a Ellipsoid. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESSolid_ToolEllipsoid.def(py::init<>());
	cls_IGESSolid_ToolEllipsoid.def("ReadOwnParams", (void (IGESSolid_ToolEllipsoid::*)(const opencascade::handle<IGESSolid_Ellipsoid> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESSolid_ToolEllipsoid::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESSolid_ToolEllipsoid.def("WriteOwnParams", (void (IGESSolid_ToolEllipsoid::*)(const opencascade::handle<IGESSolid_Ellipsoid> &, IGESData_IGESWriter &) const ) &IGESSolid_ToolEllipsoid::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESSolid_ToolEllipsoid.def("OwnShared", (void (IGESSolid_ToolEllipsoid::*)(const opencascade::handle<IGESSolid_Ellipsoid> &, Interface_EntityIterator &) const ) &IGESSolid_ToolEllipsoid::OwnShared, "Lists the Entities shared by a Ellipsoid <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESSolid_ToolEllipsoid.def("DirChecker", (IGESData_DirChecker (IGESSolid_ToolEllipsoid::*)(const opencascade::handle<IGESSolid_Ellipsoid> &) const ) &IGESSolid_ToolEllipsoid::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESSolid_ToolEllipsoid.def("OwnCheck", (void (IGESSolid_ToolEllipsoid::*)(const opencascade::handle<IGESSolid_Ellipsoid> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESSolid_ToolEllipsoid::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESSolid_ToolEllipsoid.def("OwnCopy", (void (IGESSolid_ToolEllipsoid::*)(const opencascade::handle<IGESSolid_Ellipsoid> &, const opencascade::handle<IGESSolid_Ellipsoid> &, Interface_CopyTool &) const ) &IGESSolid_ToolEllipsoid::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESSolid_ToolEllipsoid.def("OwnDump", (void (IGESSolid_ToolEllipsoid::*)(const opencascade::handle<IGESSolid_Ellipsoid> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESSolid_ToolEllipsoid::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_ToolBooleanTree.hxx
	py::class_<IGESSolid_ToolBooleanTree, std::unique_ptr<IGESSolid_ToolBooleanTree, Deleter<IGESSolid_ToolBooleanTree>>> cls_IGESSolid_ToolBooleanTree(mod, "IGESSolid_ToolBooleanTree", "Tool to work on a BooleanTree. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESSolid_ToolBooleanTree.def(py::init<>());
	cls_IGESSolid_ToolBooleanTree.def("ReadOwnParams", (void (IGESSolid_ToolBooleanTree::*)(const opencascade::handle<IGESSolid_BooleanTree> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESSolid_ToolBooleanTree::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESSolid_ToolBooleanTree.def("WriteOwnParams", (void (IGESSolid_ToolBooleanTree::*)(const opencascade::handle<IGESSolid_BooleanTree> &, IGESData_IGESWriter &) const ) &IGESSolid_ToolBooleanTree::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESSolid_ToolBooleanTree.def("OwnShared", (void (IGESSolid_ToolBooleanTree::*)(const opencascade::handle<IGESSolid_BooleanTree> &, Interface_EntityIterator &) const ) &IGESSolid_ToolBooleanTree::OwnShared, "Lists the Entities shared by a BooleanTree <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESSolid_ToolBooleanTree.def("DirChecker", (IGESData_DirChecker (IGESSolid_ToolBooleanTree::*)(const opencascade::handle<IGESSolid_BooleanTree> &) const ) &IGESSolid_ToolBooleanTree::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESSolid_ToolBooleanTree.def("OwnCheck", (void (IGESSolid_ToolBooleanTree::*)(const opencascade::handle<IGESSolid_BooleanTree> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESSolid_ToolBooleanTree::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESSolid_ToolBooleanTree.def("OwnCopy", (void (IGESSolid_ToolBooleanTree::*)(const opencascade::handle<IGESSolid_BooleanTree> &, const opencascade::handle<IGESSolid_BooleanTree> &, Interface_CopyTool &) const ) &IGESSolid_ToolBooleanTree::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESSolid_ToolBooleanTree.def("OwnDump", (void (IGESSolid_ToolBooleanTree::*)(const opencascade::handle<IGESSolid_BooleanTree> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESSolid_ToolBooleanTree::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_ToolSelectedComponent.hxx
	py::class_<IGESSolid_ToolSelectedComponent, std::unique_ptr<IGESSolid_ToolSelectedComponent, Deleter<IGESSolid_ToolSelectedComponent>>> cls_IGESSolid_ToolSelectedComponent(mod, "IGESSolid_ToolSelectedComponent", "Tool to work on a SelectedComponent. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESSolid_ToolSelectedComponent.def(py::init<>());
	cls_IGESSolid_ToolSelectedComponent.def("ReadOwnParams", (void (IGESSolid_ToolSelectedComponent::*)(const opencascade::handle<IGESSolid_SelectedComponent> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESSolid_ToolSelectedComponent::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESSolid_ToolSelectedComponent.def("WriteOwnParams", (void (IGESSolid_ToolSelectedComponent::*)(const opencascade::handle<IGESSolid_SelectedComponent> &, IGESData_IGESWriter &) const ) &IGESSolid_ToolSelectedComponent::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESSolid_ToolSelectedComponent.def("OwnShared", (void (IGESSolid_ToolSelectedComponent::*)(const opencascade::handle<IGESSolid_SelectedComponent> &, Interface_EntityIterator &) const ) &IGESSolid_ToolSelectedComponent::OwnShared, "Lists the Entities shared by a SelectedComponent <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESSolid_ToolSelectedComponent.def("DirChecker", (IGESData_DirChecker (IGESSolid_ToolSelectedComponent::*)(const opencascade::handle<IGESSolid_SelectedComponent> &) const ) &IGESSolid_ToolSelectedComponent::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESSolid_ToolSelectedComponent.def("OwnCheck", (void (IGESSolid_ToolSelectedComponent::*)(const opencascade::handle<IGESSolid_SelectedComponent> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESSolid_ToolSelectedComponent::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESSolid_ToolSelectedComponent.def("OwnCopy", (void (IGESSolid_ToolSelectedComponent::*)(const opencascade::handle<IGESSolid_SelectedComponent> &, const opencascade::handle<IGESSolid_SelectedComponent> &, Interface_CopyTool &) const ) &IGESSolid_ToolSelectedComponent::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESSolid_ToolSelectedComponent.def("OwnDump", (void (IGESSolid_ToolSelectedComponent::*)(const opencascade::handle<IGESSolid_SelectedComponent> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESSolid_ToolSelectedComponent::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_ToolSolidAssembly.hxx
	py::class_<IGESSolid_ToolSolidAssembly, std::unique_ptr<IGESSolid_ToolSolidAssembly, Deleter<IGESSolid_ToolSolidAssembly>>> cls_IGESSolid_ToolSolidAssembly(mod, "IGESSolid_ToolSolidAssembly", "Tool to work on a SolidAssembly. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESSolid_ToolSolidAssembly.def(py::init<>());
	cls_IGESSolid_ToolSolidAssembly.def("ReadOwnParams", (void (IGESSolid_ToolSolidAssembly::*)(const opencascade::handle<IGESSolid_SolidAssembly> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESSolid_ToolSolidAssembly::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESSolid_ToolSolidAssembly.def("WriteOwnParams", (void (IGESSolid_ToolSolidAssembly::*)(const opencascade::handle<IGESSolid_SolidAssembly> &, IGESData_IGESWriter &) const ) &IGESSolid_ToolSolidAssembly::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESSolid_ToolSolidAssembly.def("OwnShared", (void (IGESSolid_ToolSolidAssembly::*)(const opencascade::handle<IGESSolid_SolidAssembly> &, Interface_EntityIterator &) const ) &IGESSolid_ToolSolidAssembly::OwnShared, "Lists the Entities shared by a SolidAssembly <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESSolid_ToolSolidAssembly.def("DirChecker", (IGESData_DirChecker (IGESSolid_ToolSolidAssembly::*)(const opencascade::handle<IGESSolid_SolidAssembly> &) const ) &IGESSolid_ToolSolidAssembly::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESSolid_ToolSolidAssembly.def("OwnCheck", (void (IGESSolid_ToolSolidAssembly::*)(const opencascade::handle<IGESSolid_SolidAssembly> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESSolid_ToolSolidAssembly::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESSolid_ToolSolidAssembly.def("OwnCopy", (void (IGESSolid_ToolSolidAssembly::*)(const opencascade::handle<IGESSolid_SolidAssembly> &, const opencascade::handle<IGESSolid_SolidAssembly> &, Interface_CopyTool &) const ) &IGESSolid_ToolSolidAssembly::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESSolid_ToolSolidAssembly.def("OwnDump", (void (IGESSolid_ToolSolidAssembly::*)(const opencascade::handle<IGESSolid_SolidAssembly> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESSolid_ToolSolidAssembly::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_ToolManifoldSolid.hxx
	py::class_<IGESSolid_ToolManifoldSolid, std::unique_ptr<IGESSolid_ToolManifoldSolid, Deleter<IGESSolid_ToolManifoldSolid>>> cls_IGESSolid_ToolManifoldSolid(mod, "IGESSolid_ToolManifoldSolid", "Tool to work on a ManifoldSolid. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESSolid_ToolManifoldSolid.def(py::init<>());
	cls_IGESSolid_ToolManifoldSolid.def("ReadOwnParams", (void (IGESSolid_ToolManifoldSolid::*)(const opencascade::handle<IGESSolid_ManifoldSolid> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESSolid_ToolManifoldSolid::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESSolid_ToolManifoldSolid.def("WriteOwnParams", (void (IGESSolid_ToolManifoldSolid::*)(const opencascade::handle<IGESSolid_ManifoldSolid> &, IGESData_IGESWriter &) const ) &IGESSolid_ToolManifoldSolid::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESSolid_ToolManifoldSolid.def("OwnShared", (void (IGESSolid_ToolManifoldSolid::*)(const opencascade::handle<IGESSolid_ManifoldSolid> &, Interface_EntityIterator &) const ) &IGESSolid_ToolManifoldSolid::OwnShared, "Lists the Entities shared by a ManifoldSolid <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESSolid_ToolManifoldSolid.def("DirChecker", (IGESData_DirChecker (IGESSolid_ToolManifoldSolid::*)(const opencascade::handle<IGESSolid_ManifoldSolid> &) const ) &IGESSolid_ToolManifoldSolid::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESSolid_ToolManifoldSolid.def("OwnCheck", (void (IGESSolid_ToolManifoldSolid::*)(const opencascade::handle<IGESSolid_ManifoldSolid> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESSolid_ToolManifoldSolid::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESSolid_ToolManifoldSolid.def("OwnCopy", (void (IGESSolid_ToolManifoldSolid::*)(const opencascade::handle<IGESSolid_ManifoldSolid> &, const opencascade::handle<IGESSolid_ManifoldSolid> &, Interface_CopyTool &) const ) &IGESSolid_ToolManifoldSolid::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESSolid_ToolManifoldSolid.def("OwnDump", (void (IGESSolid_ToolManifoldSolid::*)(const opencascade::handle<IGESSolid_ManifoldSolid> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESSolid_ToolManifoldSolid::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_ToolPlaneSurface.hxx
	py::class_<IGESSolid_ToolPlaneSurface, std::unique_ptr<IGESSolid_ToolPlaneSurface, Deleter<IGESSolid_ToolPlaneSurface>>> cls_IGESSolid_ToolPlaneSurface(mod, "IGESSolid_ToolPlaneSurface", "Tool to work on a PlaneSurface. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESSolid_ToolPlaneSurface.def(py::init<>());
	cls_IGESSolid_ToolPlaneSurface.def("ReadOwnParams", (void (IGESSolid_ToolPlaneSurface::*)(const opencascade::handle<IGESSolid_PlaneSurface> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESSolid_ToolPlaneSurface::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESSolid_ToolPlaneSurface.def("WriteOwnParams", (void (IGESSolid_ToolPlaneSurface::*)(const opencascade::handle<IGESSolid_PlaneSurface> &, IGESData_IGESWriter &) const ) &IGESSolid_ToolPlaneSurface::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESSolid_ToolPlaneSurface.def("OwnShared", (void (IGESSolid_ToolPlaneSurface::*)(const opencascade::handle<IGESSolid_PlaneSurface> &, Interface_EntityIterator &) const ) &IGESSolid_ToolPlaneSurface::OwnShared, "Lists the Entities shared by a PlaneSurface <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESSolid_ToolPlaneSurface.def("DirChecker", (IGESData_DirChecker (IGESSolid_ToolPlaneSurface::*)(const opencascade::handle<IGESSolid_PlaneSurface> &) const ) &IGESSolid_ToolPlaneSurface::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESSolid_ToolPlaneSurface.def("OwnCheck", (void (IGESSolid_ToolPlaneSurface::*)(const opencascade::handle<IGESSolid_PlaneSurface> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESSolid_ToolPlaneSurface::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESSolid_ToolPlaneSurface.def("OwnCopy", (void (IGESSolid_ToolPlaneSurface::*)(const opencascade::handle<IGESSolid_PlaneSurface> &, const opencascade::handle<IGESSolid_PlaneSurface> &, Interface_CopyTool &) const ) &IGESSolid_ToolPlaneSurface::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESSolid_ToolPlaneSurface.def("OwnDump", (void (IGESSolid_ToolPlaneSurface::*)(const opencascade::handle<IGESSolid_PlaneSurface> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESSolid_ToolPlaneSurface::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_ToolCylindricalSurface.hxx
	py::class_<IGESSolid_ToolCylindricalSurface, std::unique_ptr<IGESSolid_ToolCylindricalSurface, Deleter<IGESSolid_ToolCylindricalSurface>>> cls_IGESSolid_ToolCylindricalSurface(mod, "IGESSolid_ToolCylindricalSurface", "Tool to work on a CylindricalSurface. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESSolid_ToolCylindricalSurface.def(py::init<>());
	cls_IGESSolid_ToolCylindricalSurface.def("ReadOwnParams", (void (IGESSolid_ToolCylindricalSurface::*)(const opencascade::handle<IGESSolid_CylindricalSurface> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESSolid_ToolCylindricalSurface::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESSolid_ToolCylindricalSurface.def("WriteOwnParams", (void (IGESSolid_ToolCylindricalSurface::*)(const opencascade::handle<IGESSolid_CylindricalSurface> &, IGESData_IGESWriter &) const ) &IGESSolid_ToolCylindricalSurface::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESSolid_ToolCylindricalSurface.def("OwnShared", (void (IGESSolid_ToolCylindricalSurface::*)(const opencascade::handle<IGESSolid_CylindricalSurface> &, Interface_EntityIterator &) const ) &IGESSolid_ToolCylindricalSurface::OwnShared, "Lists the Entities shared by a CylindricalSurface <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESSolid_ToolCylindricalSurface.def("DirChecker", (IGESData_DirChecker (IGESSolid_ToolCylindricalSurface::*)(const opencascade::handle<IGESSolid_CylindricalSurface> &) const ) &IGESSolid_ToolCylindricalSurface::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESSolid_ToolCylindricalSurface.def("OwnCheck", (void (IGESSolid_ToolCylindricalSurface::*)(const opencascade::handle<IGESSolid_CylindricalSurface> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESSolid_ToolCylindricalSurface::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESSolid_ToolCylindricalSurface.def("OwnCopy", (void (IGESSolid_ToolCylindricalSurface::*)(const opencascade::handle<IGESSolid_CylindricalSurface> &, const opencascade::handle<IGESSolid_CylindricalSurface> &, Interface_CopyTool &) const ) &IGESSolid_ToolCylindricalSurface::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESSolid_ToolCylindricalSurface.def("OwnDump", (void (IGESSolid_ToolCylindricalSurface::*)(const opencascade::handle<IGESSolid_CylindricalSurface> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESSolid_ToolCylindricalSurface::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_ToolConicalSurface.hxx
	py::class_<IGESSolid_ToolConicalSurface, std::unique_ptr<IGESSolid_ToolConicalSurface, Deleter<IGESSolid_ToolConicalSurface>>> cls_IGESSolid_ToolConicalSurface(mod, "IGESSolid_ToolConicalSurface", "Tool to work on a ConicalSurface. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESSolid_ToolConicalSurface.def(py::init<>());
	cls_IGESSolid_ToolConicalSurface.def("ReadOwnParams", (void (IGESSolid_ToolConicalSurface::*)(const opencascade::handle<IGESSolid_ConicalSurface> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESSolid_ToolConicalSurface::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESSolid_ToolConicalSurface.def("WriteOwnParams", (void (IGESSolid_ToolConicalSurface::*)(const opencascade::handle<IGESSolid_ConicalSurface> &, IGESData_IGESWriter &) const ) &IGESSolid_ToolConicalSurface::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESSolid_ToolConicalSurface.def("OwnShared", (void (IGESSolid_ToolConicalSurface::*)(const opencascade::handle<IGESSolid_ConicalSurface> &, Interface_EntityIterator &) const ) &IGESSolid_ToolConicalSurface::OwnShared, "Lists the Entities shared by a ConicalSurface <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESSolid_ToolConicalSurface.def("DirChecker", (IGESData_DirChecker (IGESSolid_ToolConicalSurface::*)(const opencascade::handle<IGESSolid_ConicalSurface> &) const ) &IGESSolid_ToolConicalSurface::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESSolid_ToolConicalSurface.def("OwnCheck", (void (IGESSolid_ToolConicalSurface::*)(const opencascade::handle<IGESSolid_ConicalSurface> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESSolid_ToolConicalSurface::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESSolid_ToolConicalSurface.def("OwnCopy", (void (IGESSolid_ToolConicalSurface::*)(const opencascade::handle<IGESSolid_ConicalSurface> &, const opencascade::handle<IGESSolid_ConicalSurface> &, Interface_CopyTool &) const ) &IGESSolid_ToolConicalSurface::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESSolid_ToolConicalSurface.def("OwnDump", (void (IGESSolid_ToolConicalSurface::*)(const opencascade::handle<IGESSolid_ConicalSurface> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESSolid_ToolConicalSurface::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_ToolSphericalSurface.hxx
	py::class_<IGESSolid_ToolSphericalSurface, std::unique_ptr<IGESSolid_ToolSphericalSurface, Deleter<IGESSolid_ToolSphericalSurface>>> cls_IGESSolid_ToolSphericalSurface(mod, "IGESSolid_ToolSphericalSurface", "Tool to work on a SphericalSurface. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESSolid_ToolSphericalSurface.def(py::init<>());
	cls_IGESSolid_ToolSphericalSurface.def("ReadOwnParams", (void (IGESSolid_ToolSphericalSurface::*)(const opencascade::handle<IGESSolid_SphericalSurface> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESSolid_ToolSphericalSurface::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESSolid_ToolSphericalSurface.def("WriteOwnParams", (void (IGESSolid_ToolSphericalSurface::*)(const opencascade::handle<IGESSolid_SphericalSurface> &, IGESData_IGESWriter &) const ) &IGESSolid_ToolSphericalSurface::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESSolid_ToolSphericalSurface.def("OwnShared", (void (IGESSolid_ToolSphericalSurface::*)(const opencascade::handle<IGESSolid_SphericalSurface> &, Interface_EntityIterator &) const ) &IGESSolid_ToolSphericalSurface::OwnShared, "Lists the Entities shared by a SphericalSurface <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESSolid_ToolSphericalSurface.def("DirChecker", (IGESData_DirChecker (IGESSolid_ToolSphericalSurface::*)(const opencascade::handle<IGESSolid_SphericalSurface> &) const ) &IGESSolid_ToolSphericalSurface::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESSolid_ToolSphericalSurface.def("OwnCheck", (void (IGESSolid_ToolSphericalSurface::*)(const opencascade::handle<IGESSolid_SphericalSurface> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESSolid_ToolSphericalSurface::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESSolid_ToolSphericalSurface.def("OwnCopy", (void (IGESSolid_ToolSphericalSurface::*)(const opencascade::handle<IGESSolid_SphericalSurface> &, const opencascade::handle<IGESSolid_SphericalSurface> &, Interface_CopyTool &) const ) &IGESSolid_ToolSphericalSurface::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESSolid_ToolSphericalSurface.def("OwnDump", (void (IGESSolid_ToolSphericalSurface::*)(const opencascade::handle<IGESSolid_SphericalSurface> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESSolid_ToolSphericalSurface::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_ToolToroidalSurface.hxx
	py::class_<IGESSolid_ToolToroidalSurface, std::unique_ptr<IGESSolid_ToolToroidalSurface, Deleter<IGESSolid_ToolToroidalSurface>>> cls_IGESSolid_ToolToroidalSurface(mod, "IGESSolid_ToolToroidalSurface", "Tool to work on a ToroidalSurface. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESSolid_ToolToroidalSurface.def(py::init<>());
	cls_IGESSolid_ToolToroidalSurface.def("ReadOwnParams", (void (IGESSolid_ToolToroidalSurface::*)(const opencascade::handle<IGESSolid_ToroidalSurface> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESSolid_ToolToroidalSurface::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESSolid_ToolToroidalSurface.def("WriteOwnParams", (void (IGESSolid_ToolToroidalSurface::*)(const opencascade::handle<IGESSolid_ToroidalSurface> &, IGESData_IGESWriter &) const ) &IGESSolid_ToolToroidalSurface::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESSolid_ToolToroidalSurface.def("OwnShared", (void (IGESSolid_ToolToroidalSurface::*)(const opencascade::handle<IGESSolid_ToroidalSurface> &, Interface_EntityIterator &) const ) &IGESSolid_ToolToroidalSurface::OwnShared, "Lists the Entities shared by a ToroidalSurface <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESSolid_ToolToroidalSurface.def("DirChecker", (IGESData_DirChecker (IGESSolid_ToolToroidalSurface::*)(const opencascade::handle<IGESSolid_ToroidalSurface> &) const ) &IGESSolid_ToolToroidalSurface::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESSolid_ToolToroidalSurface.def("OwnCheck", (void (IGESSolid_ToolToroidalSurface::*)(const opencascade::handle<IGESSolid_ToroidalSurface> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESSolid_ToolToroidalSurface::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESSolid_ToolToroidalSurface.def("OwnCopy", (void (IGESSolid_ToolToroidalSurface::*)(const opencascade::handle<IGESSolid_ToroidalSurface> &, const opencascade::handle<IGESSolid_ToroidalSurface> &, Interface_CopyTool &) const ) &IGESSolid_ToolToroidalSurface::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESSolid_ToolToroidalSurface.def("OwnDump", (void (IGESSolid_ToolToroidalSurface::*)(const opencascade::handle<IGESSolid_ToroidalSurface> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESSolid_ToolToroidalSurface::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_ToolSolidInstance.hxx
	py::class_<IGESSolid_ToolSolidInstance, std::unique_ptr<IGESSolid_ToolSolidInstance, Deleter<IGESSolid_ToolSolidInstance>>> cls_IGESSolid_ToolSolidInstance(mod, "IGESSolid_ToolSolidInstance", "Tool to work on a SolidInstance. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESSolid_ToolSolidInstance.def(py::init<>());
	cls_IGESSolid_ToolSolidInstance.def("ReadOwnParams", (void (IGESSolid_ToolSolidInstance::*)(const opencascade::handle<IGESSolid_SolidInstance> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESSolid_ToolSolidInstance::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESSolid_ToolSolidInstance.def("WriteOwnParams", (void (IGESSolid_ToolSolidInstance::*)(const opencascade::handle<IGESSolid_SolidInstance> &, IGESData_IGESWriter &) const ) &IGESSolid_ToolSolidInstance::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESSolid_ToolSolidInstance.def("OwnShared", (void (IGESSolid_ToolSolidInstance::*)(const opencascade::handle<IGESSolid_SolidInstance> &, Interface_EntityIterator &) const ) &IGESSolid_ToolSolidInstance::OwnShared, "Lists the Entities shared by a SolidInstance <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESSolid_ToolSolidInstance.def("DirChecker", (IGESData_DirChecker (IGESSolid_ToolSolidInstance::*)(const opencascade::handle<IGESSolid_SolidInstance> &) const ) &IGESSolid_ToolSolidInstance::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESSolid_ToolSolidInstance.def("OwnCheck", (void (IGESSolid_ToolSolidInstance::*)(const opencascade::handle<IGESSolid_SolidInstance> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESSolid_ToolSolidInstance::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESSolid_ToolSolidInstance.def("OwnCopy", (void (IGESSolid_ToolSolidInstance::*)(const opencascade::handle<IGESSolid_SolidInstance> &, const opencascade::handle<IGESSolid_SolidInstance> &, Interface_CopyTool &) const ) &IGESSolid_ToolSolidInstance::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESSolid_ToolSolidInstance.def("OwnDump", (void (IGESSolid_ToolSolidInstance::*)(const opencascade::handle<IGESSolid_SolidInstance> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESSolid_ToolSolidInstance::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_ToolVertexList.hxx
	py::class_<IGESSolid_ToolVertexList, std::unique_ptr<IGESSolid_ToolVertexList, Deleter<IGESSolid_ToolVertexList>>> cls_IGESSolid_ToolVertexList(mod, "IGESSolid_ToolVertexList", "Tool to work on a VertexList. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESSolid_ToolVertexList.def(py::init<>());
	cls_IGESSolid_ToolVertexList.def("ReadOwnParams", (void (IGESSolid_ToolVertexList::*)(const opencascade::handle<IGESSolid_VertexList> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESSolid_ToolVertexList::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESSolid_ToolVertexList.def("WriteOwnParams", (void (IGESSolid_ToolVertexList::*)(const opencascade::handle<IGESSolid_VertexList> &, IGESData_IGESWriter &) const ) &IGESSolid_ToolVertexList::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESSolid_ToolVertexList.def("OwnShared", (void (IGESSolid_ToolVertexList::*)(const opencascade::handle<IGESSolid_VertexList> &, Interface_EntityIterator &) const ) &IGESSolid_ToolVertexList::OwnShared, "Lists the Entities shared by a VertexList <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESSolid_ToolVertexList.def("DirChecker", (IGESData_DirChecker (IGESSolid_ToolVertexList::*)(const opencascade::handle<IGESSolid_VertexList> &) const ) &IGESSolid_ToolVertexList::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESSolid_ToolVertexList.def("OwnCheck", (void (IGESSolid_ToolVertexList::*)(const opencascade::handle<IGESSolid_VertexList> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESSolid_ToolVertexList::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESSolid_ToolVertexList.def("OwnCopy", (void (IGESSolid_ToolVertexList::*)(const opencascade::handle<IGESSolid_VertexList> &, const opencascade::handle<IGESSolid_VertexList> &, Interface_CopyTool &) const ) &IGESSolid_ToolVertexList::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESSolid_ToolVertexList.def("OwnDump", (void (IGESSolid_ToolVertexList::*)(const opencascade::handle<IGESSolid_VertexList> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESSolid_ToolVertexList::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_ToolEdgeList.hxx
	py::class_<IGESSolid_ToolEdgeList, std::unique_ptr<IGESSolid_ToolEdgeList, Deleter<IGESSolid_ToolEdgeList>>> cls_IGESSolid_ToolEdgeList(mod, "IGESSolid_ToolEdgeList", "Tool to work on a EdgeList. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESSolid_ToolEdgeList.def(py::init<>());
	cls_IGESSolid_ToolEdgeList.def("ReadOwnParams", (void (IGESSolid_ToolEdgeList::*)(const opencascade::handle<IGESSolid_EdgeList> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESSolid_ToolEdgeList::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESSolid_ToolEdgeList.def("WriteOwnParams", (void (IGESSolid_ToolEdgeList::*)(const opencascade::handle<IGESSolid_EdgeList> &, IGESData_IGESWriter &) const ) &IGESSolid_ToolEdgeList::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESSolid_ToolEdgeList.def("OwnShared", (void (IGESSolid_ToolEdgeList::*)(const opencascade::handle<IGESSolid_EdgeList> &, Interface_EntityIterator &) const ) &IGESSolid_ToolEdgeList::OwnShared, "Lists the Entities shared by a EdgeList <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESSolid_ToolEdgeList.def("DirChecker", (IGESData_DirChecker (IGESSolid_ToolEdgeList::*)(const opencascade::handle<IGESSolid_EdgeList> &) const ) &IGESSolid_ToolEdgeList::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESSolid_ToolEdgeList.def("OwnCheck", (void (IGESSolid_ToolEdgeList::*)(const opencascade::handle<IGESSolid_EdgeList> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESSolid_ToolEdgeList::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESSolid_ToolEdgeList.def("OwnCopy", (void (IGESSolid_ToolEdgeList::*)(const opencascade::handle<IGESSolid_EdgeList> &, const opencascade::handle<IGESSolid_EdgeList> &, Interface_CopyTool &) const ) &IGESSolid_ToolEdgeList::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESSolid_ToolEdgeList.def("OwnDump", (void (IGESSolid_ToolEdgeList::*)(const opencascade::handle<IGESSolid_EdgeList> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESSolid_ToolEdgeList::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_ToolLoop.hxx
	py::class_<IGESSolid_ToolLoop, std::unique_ptr<IGESSolid_ToolLoop, Deleter<IGESSolid_ToolLoop>>> cls_IGESSolid_ToolLoop(mod, "IGESSolid_ToolLoop", "Tool to work on a Loop. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESSolid_ToolLoop.def(py::init<>());
	cls_IGESSolid_ToolLoop.def("ReadOwnParams", (void (IGESSolid_ToolLoop::*)(const opencascade::handle<IGESSolid_Loop> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESSolid_ToolLoop::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESSolid_ToolLoop.def("WriteOwnParams", (void (IGESSolid_ToolLoop::*)(const opencascade::handle<IGESSolid_Loop> &, IGESData_IGESWriter &) const ) &IGESSolid_ToolLoop::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESSolid_ToolLoop.def("OwnShared", (void (IGESSolid_ToolLoop::*)(const opencascade::handle<IGESSolid_Loop> &, Interface_EntityIterator &) const ) &IGESSolid_ToolLoop::OwnShared, "Lists the Entities shared by a Loop <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESSolid_ToolLoop.def("DirChecker", (IGESData_DirChecker (IGESSolid_ToolLoop::*)(const opencascade::handle<IGESSolid_Loop> &) const ) &IGESSolid_ToolLoop::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESSolid_ToolLoop.def("OwnCheck", (void (IGESSolid_ToolLoop::*)(const opencascade::handle<IGESSolid_Loop> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESSolid_ToolLoop::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESSolid_ToolLoop.def("OwnCopy", (void (IGESSolid_ToolLoop::*)(const opencascade::handle<IGESSolid_Loop> &, const opencascade::handle<IGESSolid_Loop> &, Interface_CopyTool &) const ) &IGESSolid_ToolLoop::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESSolid_ToolLoop.def("OwnDump", (void (IGESSolid_ToolLoop::*)(const opencascade::handle<IGESSolid_Loop> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESSolid_ToolLoop::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_ToolFace.hxx
	py::class_<IGESSolid_ToolFace, std::unique_ptr<IGESSolid_ToolFace, Deleter<IGESSolid_ToolFace>>> cls_IGESSolid_ToolFace(mod, "IGESSolid_ToolFace", "Tool to work on a Face. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESSolid_ToolFace.def(py::init<>());
	cls_IGESSolid_ToolFace.def("ReadOwnParams", (void (IGESSolid_ToolFace::*)(const opencascade::handle<IGESSolid_Face> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESSolid_ToolFace::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESSolid_ToolFace.def("WriteOwnParams", (void (IGESSolid_ToolFace::*)(const opencascade::handle<IGESSolid_Face> &, IGESData_IGESWriter &) const ) &IGESSolid_ToolFace::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESSolid_ToolFace.def("OwnShared", (void (IGESSolid_ToolFace::*)(const opencascade::handle<IGESSolid_Face> &, Interface_EntityIterator &) const ) &IGESSolid_ToolFace::OwnShared, "Lists the Entities shared by a Face <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESSolid_ToolFace.def("DirChecker", (IGESData_DirChecker (IGESSolid_ToolFace::*)(const opencascade::handle<IGESSolid_Face> &) const ) &IGESSolid_ToolFace::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESSolid_ToolFace.def("OwnCheck", (void (IGESSolid_ToolFace::*)(const opencascade::handle<IGESSolid_Face> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESSolid_ToolFace::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESSolid_ToolFace.def("OwnCopy", (void (IGESSolid_ToolFace::*)(const opencascade::handle<IGESSolid_Face> &, const opencascade::handle<IGESSolid_Face> &, Interface_CopyTool &) const ) &IGESSolid_ToolFace::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESSolid_ToolFace.def("OwnDump", (void (IGESSolid_ToolFace::*)(const opencascade::handle<IGESSolid_Face> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESSolid_ToolFace::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_ToolShell.hxx
	py::class_<IGESSolid_ToolShell, std::unique_ptr<IGESSolid_ToolShell, Deleter<IGESSolid_ToolShell>>> cls_IGESSolid_ToolShell(mod, "IGESSolid_ToolShell", "Tool to work on a Shell. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESSolid_ToolShell.def(py::init<>());
	cls_IGESSolid_ToolShell.def("ReadOwnParams", (void (IGESSolid_ToolShell::*)(const opencascade::handle<IGESSolid_Shell> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESSolid_ToolShell::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESSolid_ToolShell.def("WriteOwnParams", (void (IGESSolid_ToolShell::*)(const opencascade::handle<IGESSolid_Shell> &, IGESData_IGESWriter &) const ) &IGESSolid_ToolShell::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESSolid_ToolShell.def("OwnShared", (void (IGESSolid_ToolShell::*)(const opencascade::handle<IGESSolid_Shell> &, Interface_EntityIterator &) const ) &IGESSolid_ToolShell::OwnShared, "Lists the Entities shared by a Shell <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESSolid_ToolShell.def("DirChecker", (IGESData_DirChecker (IGESSolid_ToolShell::*)(const opencascade::handle<IGESSolid_Shell> &) const ) &IGESSolid_ToolShell::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESSolid_ToolShell.def("OwnCheck", (void (IGESSolid_ToolShell::*)(const opencascade::handle<IGESSolid_Shell> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESSolid_ToolShell::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESSolid_ToolShell.def("OwnCopy", (void (IGESSolid_ToolShell::*)(const opencascade::handle<IGESSolid_Shell> &, const opencascade::handle<IGESSolid_Shell> &, Interface_CopyTool &) const ) &IGESSolid_ToolShell::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESSolid_ToolShell.def("OwnDump", (void (IGESSolid_ToolShell::*)(const opencascade::handle<IGESSolid_Shell> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESSolid_ToolShell::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_ReadWriteModule.hxx
	py::class_<IGESSolid_ReadWriteModule, opencascade::handle<IGESSolid_ReadWriteModule>, IGESData_ReadWriteModule> cls_IGESSolid_ReadWriteModule(mod, "IGESSolid_ReadWriteModule", "Defines Solid File Access Module for IGESSolid (specific parts) Specific actions concern : Read and Write Own Parameters of an IGESEntity.");
	cls_IGESSolid_ReadWriteModule.def(py::init<>());
	cls_IGESSolid_ReadWriteModule.def("CaseIGES", (Standard_Integer (IGESSolid_ReadWriteModule::*)(const Standard_Integer, const Standard_Integer) const ) &IGESSolid_ReadWriteModule::CaseIGES, "Defines Case Numbers for Entities of IGESSolid", py::arg("typenum"), py::arg("formnum"));
	cls_IGESSolid_ReadWriteModule.def("ReadOwnParams", (void (IGESSolid_ReadWriteModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESSolid_ReadWriteModule::ReadOwnParams, "Reads own parameters from file for an Entity of IGESSolid", py::arg("CN"), py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESSolid_ReadWriteModule.def("WriteOwnParams", (void (IGESSolid_ReadWriteModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, IGESData_IGESWriter &) const ) &IGESSolid_ReadWriteModule::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("CN"), py::arg("ent"), py::arg("IW"));
	cls_IGESSolid_ReadWriteModule.def_static("get_type_name_", (const char * (*)()) &IGESSolid_ReadWriteModule::get_type_name, "None");
	cls_IGESSolid_ReadWriteModule.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_ReadWriteModule::get_type_descriptor, "None");
	cls_IGESSolid_ReadWriteModule.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_ReadWriteModule::*)() const ) &IGESSolid_ReadWriteModule::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_GeneralModule.hxx
	py::class_<IGESSolid_GeneralModule, opencascade::handle<IGESSolid_GeneralModule>, IGESData_GeneralModule> cls_IGESSolid_GeneralModule(mod, "IGESSolid_GeneralModule", "Definition of General Services for IGESSolid (specific part) This Services comprise : Shared & Implied Lists, Copy, Check");
	cls_IGESSolid_GeneralModule.def(py::init<>());
	cls_IGESSolid_GeneralModule.def("OwnSharedCase", (void (IGESSolid_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, Interface_EntityIterator &) const ) &IGESSolid_GeneralModule::OwnSharedCase, "Lists the Entities shared by a given IGESEntity <ent>, from its specific parameters : specific for each type", py::arg("CN"), py::arg("ent"), py::arg("iter"));
	cls_IGESSolid_GeneralModule.def("DirChecker", (IGESData_DirChecker (IGESSolid_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &) const ) &IGESSolid_GeneralModule::DirChecker, "Returns a DirChecker, specific for each type of Entity (identified by its Case Number) : this DirChecker defines constraints which must be respected by the DirectoryPart", py::arg("CN"), py::arg("ent"));
	cls_IGESSolid_GeneralModule.def("OwnCheckCase", (void (IGESSolid_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESSolid_GeneralModule::OwnCheckCase, "Performs Specific Semantic Check for each type of Entity", py::arg("CN"), py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESSolid_GeneralModule.def("NewVoid", (Standard_Boolean (IGESSolid_GeneralModule::*)(const Standard_Integer, opencascade::handle<Standard_Transient> &) const ) &IGESSolid_GeneralModule::NewVoid, "Specific creation of a new void entity", py::arg("CN"), py::arg("entto"));
	cls_IGESSolid_GeneralModule.def("OwnCopyCase", (void (IGESSolid_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_IGESEntity> &, Interface_CopyTool &) const ) &IGESSolid_GeneralModule::OwnCopyCase, "Copies parameters which are specific of each Type of Entity", py::arg("CN"), py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESSolid_GeneralModule.def("CategoryNumber", (Standard_Integer (IGESSolid_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_ShareTool &) const ) &IGESSolid_GeneralModule::CategoryNumber, "Returns a category number which characterizes an entity Shape for all", py::arg("CN"), py::arg("ent"), py::arg("shares"));
	cls_IGESSolid_GeneralModule.def_static("get_type_name_", (const char * (*)()) &IGESSolid_GeneralModule::get_type_name, "None");
	cls_IGESSolid_GeneralModule.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_GeneralModule::get_type_descriptor, "None");
	cls_IGESSolid_GeneralModule.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_GeneralModule::*)() const ) &IGESSolid_GeneralModule::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_SpecificModule.hxx
	py::class_<IGESSolid_SpecificModule, opencascade::handle<IGESSolid_SpecificModule>, IGESData_SpecificModule> cls_IGESSolid_SpecificModule(mod, "IGESSolid_SpecificModule", "Defines Services attached to IGES Entities : Dump, for IGESSolid");
	cls_IGESSolid_SpecificModule.def(py::init<>());
	cls_IGESSolid_SpecificModule.def("OwnDump", (void (IGESSolid_SpecificModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESSolid_SpecificModule::OwnDump, "Specific Dump (own parameters) for IGESSolid", py::arg("CN"), py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));
	cls_IGESSolid_SpecificModule.def_static("get_type_name_", (const char * (*)()) &IGESSolid_SpecificModule::get_type_name, "None");
	cls_IGESSolid_SpecificModule.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_SpecificModule::get_type_descriptor, "None");
	cls_IGESSolid_SpecificModule.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_SpecificModule::*)() const ) &IGESSolid_SpecificModule::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_TopoBuilder.hxx
	py::class_<IGESSolid_TopoBuilder, std::unique_ptr<IGESSolid_TopoBuilder, Deleter<IGESSolid_TopoBuilder>>> cls_IGESSolid_TopoBuilder(mod, "IGESSolid_TopoBuilder", "This class manages the creation of an IGES Topologic entity (BREP : ManifoldSolid, Shell, Face) This includes definiting of Vertex and Edge Lists, building of Edges and Loops");
	cls_IGESSolid_TopoBuilder.def(py::init<>());
	cls_IGESSolid_TopoBuilder.def("Clear", (void (IGESSolid_TopoBuilder::*)()) &IGESSolid_TopoBuilder::Clear, "Resets the TopoBuilder for an entirely new operation (with a new EdgeList, a new VertexList, new Shells, ...)");
	cls_IGESSolid_TopoBuilder.def("AddVertex", (void (IGESSolid_TopoBuilder::*)(const gp_XYZ &)) &IGESSolid_TopoBuilder::AddVertex, "Adds a Vertex to the VertexList", py::arg("val"));
	cls_IGESSolid_TopoBuilder.def("NbVertices", (Standard_Integer (IGESSolid_TopoBuilder::*)() const ) &IGESSolid_TopoBuilder::NbVertices, "Returns the count of already recorded Vertices");
	cls_IGESSolid_TopoBuilder.def("Vertex", (const gp_XYZ & (IGESSolid_TopoBuilder::*)(const Standard_Integer) const ) &IGESSolid_TopoBuilder::Vertex, "Returns a Vertex, given its rank", py::arg("num"));
	cls_IGESSolid_TopoBuilder.def("VertexList", (opencascade::handle<IGESSolid_VertexList> (IGESSolid_TopoBuilder::*)() const ) &IGESSolid_TopoBuilder::VertexList, "Returns the VertexList. It can be referenced, but it remains empty until call to EndShell or EndSolid");
	cls_IGESSolid_TopoBuilder.def("AddEdge", (void (IGESSolid_TopoBuilder::*)(const opencascade::handle<IGESData_IGESEntity> &, const Standard_Integer, const Standard_Integer)) &IGESSolid_TopoBuilder::AddEdge, "Adds an Edge (3D) to the EdgeList, defined by a Curve and two number of Vertex, for start and end", py::arg("curve"), py::arg("vstart"), py::arg("vend"));
	cls_IGESSolid_TopoBuilder.def("NbEdges", (Standard_Integer (IGESSolid_TopoBuilder::*)() const ) &IGESSolid_TopoBuilder::NbEdges, "Returns the count of recorded Edges (3D)");
	cls_IGESSolid_TopoBuilder.def("Edge", [](IGESSolid_TopoBuilder &self, const Standard_Integer num, opencascade::handle<IGESData_IGESEntity> & curve, Standard_Integer & vstart, Standard_Integer & vend){ self.Edge(num, curve, vstart, vend); return std::tuple<Standard_Integer &, Standard_Integer &>(vstart, vend); }, "Returns the definition of an Edge (3D) given its rank", py::arg("num"), py::arg("curve"), py::arg("vstart"), py::arg("vend"));
	cls_IGESSolid_TopoBuilder.def("EdgeList", (opencascade::handle<IGESSolid_EdgeList> (IGESSolid_TopoBuilder::*)() const ) &IGESSolid_TopoBuilder::EdgeList, "Returns the EdgeList. It can be referenced, but it remains empty until call to EndShell or EndSolid");
	cls_IGESSolid_TopoBuilder.def("MakeLoop", (void (IGESSolid_TopoBuilder::*)()) &IGESSolid_TopoBuilder::MakeLoop, "Begins the definition of a new Loop : it is the Current Loop All Edges (UV) defined by MakeEdge/EndEdge will be added in it The Loop can then be referenced but is empty. It will be filled with its Edges(UV) by EndLoop (from SetOuter/AddInner)");
	cls_IGESSolid_TopoBuilder.def("MakeEdge", (void (IGESSolid_TopoBuilder::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer)) &IGESSolid_TopoBuilder::MakeEdge, "Defines an Edge(UV), to be added in the current Loop by EndEdge <edgetype> gives the type of the edge <edge3d> identifies the Edge(3D) used as support The EdgeList is allways the current one <orientation gives the orientation flag It is then necessary to : - give the parametric curves - close the definition of this edge(UV) by EndEdge, else the next call to MakeEdge will erase this one", py::arg("edgetype"), py::arg("edge3d"), py::arg("orientation"));
	cls_IGESSolid_TopoBuilder.def("AddCurveUV", (void (IGESSolid_TopoBuilder::*)(const opencascade::handle<IGESData_IGESEntity> &, const Standard_Integer)) &IGESSolid_TopoBuilder::AddCurveUV, "Adds a Parametric Curve (UV) to the current Edge(UV)", py::arg("curve"), py::arg("iso"));
	cls_IGESSolid_TopoBuilder.def("EndEdge", (void (IGESSolid_TopoBuilder::*)()) &IGESSolid_TopoBuilder::EndEdge, "Closes the definition of an Edge(UV) and adds it to the current Loop");
	cls_IGESSolid_TopoBuilder.def("MakeFace", (void (IGESSolid_TopoBuilder::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESSolid_TopoBuilder::MakeFace, "Begins the definition of a new Face, on a surface All Loops defined by MakeLoop will be added in it, according the closing call : SetOuter for the Outer Loop (by default, if SetOuter is not called, no OuterLoop is defined); AddInner for the list of Inner Loops (there can be none)", py::arg("surface"));
	cls_IGESSolid_TopoBuilder.def("SetOuter", (void (IGESSolid_TopoBuilder::*)()) &IGESSolid_TopoBuilder::SetOuter, "Closes the current Loop and sets it Loop as Outer Loop. If no current Loop has yet been defined, does nothing.");
	cls_IGESSolid_TopoBuilder.def("AddInner", (void (IGESSolid_TopoBuilder::*)()) &IGESSolid_TopoBuilder::AddInner, "Closes the current Loop and adds it to the list of Inner Loops for the current Face");
	cls_IGESSolid_TopoBuilder.def("EndFace", (void (IGESSolid_TopoBuilder::*)(const Standard_Integer)) &IGESSolid_TopoBuilder::EndFace, "Closes the definition of the current Face, fills it and adds it to the current Shell with an orientation flag (0/1)", py::arg("orientation"));
	cls_IGESSolid_TopoBuilder.def("MakeShell", (void (IGESSolid_TopoBuilder::*)()) &IGESSolid_TopoBuilder::MakeShell, "Begins the definition of a new Shell (either Simple or in a Solid)");
	cls_IGESSolid_TopoBuilder.def("EndSimpleShell", (void (IGESSolid_TopoBuilder::*)()) &IGESSolid_TopoBuilder::EndSimpleShell, "Closes the whole definition as that of a simple Shell");
	cls_IGESSolid_TopoBuilder.def("SetMainShell", (void (IGESSolid_TopoBuilder::*)(const Standard_Integer)) &IGESSolid_TopoBuilder::SetMainShell, "Closes the definition of the current Shell as for the Main Shell of a Solid, with an orientation flag (0/1)", py::arg("orientation"));
	cls_IGESSolid_TopoBuilder.def("AddVoidShell", (void (IGESSolid_TopoBuilder::*)(const Standard_Integer)) &IGESSolid_TopoBuilder::AddVoidShell, "Closes the definition of the current Shell and adds it to the list of Void Shells of a Solid, with an orientation flag (0/1)", py::arg("orientation"));
	cls_IGESSolid_TopoBuilder.def("EndSolid", (void (IGESSolid_TopoBuilder::*)()) &IGESSolid_TopoBuilder::EndSolid, "Closes the whole definition as that of a ManifoldSolid Its call is exclusive from that of EndSimpleShell");
	cls_IGESSolid_TopoBuilder.def("Shell", (opencascade::handle<IGESSolid_Shell> (IGESSolid_TopoBuilder::*)() const ) &IGESSolid_TopoBuilder::Shell, "Returns the current Shell. The current Shell is created empty by MakeShell and filled by EndShell");
	cls_IGESSolid_TopoBuilder.def("Solid", (opencascade::handle<IGESSolid_ManifoldSolid> (IGESSolid_TopoBuilder::*)() const ) &IGESSolid_TopoBuilder::Solid, "Returns the current ManifoldSolid. It is created empty by Create and filled by EndSolid");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid.hxx
	py::class_<IGESSolid, std::unique_ptr<IGESSolid, Deleter<IGESSolid>>> cls_IGESSolid(mod, "IGESSolid", "This package consists of B-Rep and CSG Solid entities");
	cls_IGESSolid.def(py::init<>());
	cls_IGESSolid.def_static("Init_", (void (*)()) &IGESSolid::Init, "Prepares dynamic data (Protocol, Modules) for this package");
	cls_IGESSolid.def_static("Protocol_", (opencascade::handle<IGESSolid_Protocol> (*)()) &IGESSolid::Protocol, "Returns the Protocol for this Package");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_Array1OfLoop.hxx
	bind_NCollection_Array1<opencascade::handle<IGESSolid_Loop> >(mod, "IGESSolid_Array1OfLoop");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_Array1OfFace.hxx
	bind_NCollection_Array1<opencascade::handle<IGESSolid_Face> >(mod, "IGESSolid_Array1OfFace");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_Array1OfVertexList.hxx
	bind_NCollection_Array1<opencascade::handle<IGESSolid_VertexList> >(mod, "IGESSolid_Array1OfVertexList");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_Array1OfShell.hxx
	bind_NCollection_Array1<opencascade::handle<IGESSolid_Shell> >(mod, "IGESSolid_Array1OfShell");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_HArray1OfLoop.hxx
	py::class_<IGESSolid_HArray1OfLoop, opencascade::handle<IGESSolid_HArray1OfLoop>, IGESSolid_Array1OfLoop, Standard_Transient> cls_IGESSolid_HArray1OfLoop(mod, "IGESSolid_HArray1OfLoop", "None");
	cls_IGESSolid_HArray1OfLoop.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_IGESSolid_HArray1OfLoop.def(py::init<const Standard_Integer, const Standard_Integer, const IGESSolid_Array1OfLoop::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_IGESSolid_HArray1OfLoop.def(py::init<const IGESSolid_Array1OfLoop &>(), py::arg("theOther"));
	cls_IGESSolid_HArray1OfLoop.def("Array1", (const IGESSolid_Array1OfLoop & (IGESSolid_HArray1OfLoop::*)() const ) &IGESSolid_HArray1OfLoop::Array1, "None");
	cls_IGESSolid_HArray1OfLoop.def("ChangeArray1", (IGESSolid_Array1OfLoop & (IGESSolid_HArray1OfLoop::*)()) &IGESSolid_HArray1OfLoop::ChangeArray1, "None");
	cls_IGESSolid_HArray1OfLoop.def_static("get_type_name_", (const char * (*)()) &IGESSolid_HArray1OfLoop::get_type_name, "None");
	cls_IGESSolid_HArray1OfLoop.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_HArray1OfLoop::get_type_descriptor, "None");
	cls_IGESSolid_HArray1OfLoop.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_HArray1OfLoop::*)() const ) &IGESSolid_HArray1OfLoop::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_HArray1OfFace.hxx
	py::class_<IGESSolid_HArray1OfFace, opencascade::handle<IGESSolid_HArray1OfFace>, IGESSolid_Array1OfFace, Standard_Transient> cls_IGESSolid_HArray1OfFace(mod, "IGESSolid_HArray1OfFace", "None");
	cls_IGESSolid_HArray1OfFace.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_IGESSolid_HArray1OfFace.def(py::init<const Standard_Integer, const Standard_Integer, const IGESSolid_Array1OfFace::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_IGESSolid_HArray1OfFace.def(py::init<const IGESSolid_Array1OfFace &>(), py::arg("theOther"));
	cls_IGESSolid_HArray1OfFace.def("Array1", (const IGESSolid_Array1OfFace & (IGESSolid_HArray1OfFace::*)() const ) &IGESSolid_HArray1OfFace::Array1, "None");
	cls_IGESSolid_HArray1OfFace.def("ChangeArray1", (IGESSolid_Array1OfFace & (IGESSolid_HArray1OfFace::*)()) &IGESSolid_HArray1OfFace::ChangeArray1, "None");
	cls_IGESSolid_HArray1OfFace.def_static("get_type_name_", (const char * (*)()) &IGESSolid_HArray1OfFace::get_type_name, "None");
	cls_IGESSolid_HArray1OfFace.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_HArray1OfFace::get_type_descriptor, "None");
	cls_IGESSolid_HArray1OfFace.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_HArray1OfFace::*)() const ) &IGESSolid_HArray1OfFace::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_HArray1OfShell.hxx
	py::class_<IGESSolid_HArray1OfShell, opencascade::handle<IGESSolid_HArray1OfShell>, IGESSolid_Array1OfShell, Standard_Transient> cls_IGESSolid_HArray1OfShell(mod, "IGESSolid_HArray1OfShell", "None");
	cls_IGESSolid_HArray1OfShell.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_IGESSolid_HArray1OfShell.def(py::init<const Standard_Integer, const Standard_Integer, const IGESSolid_Array1OfShell::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_IGESSolid_HArray1OfShell.def(py::init<const IGESSolid_Array1OfShell &>(), py::arg("theOther"));
	cls_IGESSolid_HArray1OfShell.def("Array1", (const IGESSolid_Array1OfShell & (IGESSolid_HArray1OfShell::*)() const ) &IGESSolid_HArray1OfShell::Array1, "None");
	cls_IGESSolid_HArray1OfShell.def("ChangeArray1", (IGESSolid_Array1OfShell & (IGESSolid_HArray1OfShell::*)()) &IGESSolid_HArray1OfShell::ChangeArray1, "None");
	cls_IGESSolid_HArray1OfShell.def_static("get_type_name_", (const char * (*)()) &IGESSolid_HArray1OfShell::get_type_name, "None");
	cls_IGESSolid_HArray1OfShell.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_HArray1OfShell::get_type_descriptor, "None");
	cls_IGESSolid_HArray1OfShell.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_HArray1OfShell::*)() const ) &IGESSolid_HArray1OfShell::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESSolid_HArray1OfVertexList.hxx
	py::class_<IGESSolid_HArray1OfVertexList, opencascade::handle<IGESSolid_HArray1OfVertexList>, IGESSolid_Array1OfVertexList, Standard_Transient> cls_IGESSolid_HArray1OfVertexList(mod, "IGESSolid_HArray1OfVertexList", "None");
	cls_IGESSolid_HArray1OfVertexList.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_IGESSolid_HArray1OfVertexList.def(py::init<const Standard_Integer, const Standard_Integer, const IGESSolid_Array1OfVertexList::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_IGESSolid_HArray1OfVertexList.def(py::init<const IGESSolid_Array1OfVertexList &>(), py::arg("theOther"));
	cls_IGESSolid_HArray1OfVertexList.def("Array1", (const IGESSolid_Array1OfVertexList & (IGESSolid_HArray1OfVertexList::*)() const ) &IGESSolid_HArray1OfVertexList::Array1, "None");
	cls_IGESSolid_HArray1OfVertexList.def("ChangeArray1", (IGESSolid_Array1OfVertexList & (IGESSolid_HArray1OfVertexList::*)()) &IGESSolid_HArray1OfVertexList::ChangeArray1, "None");
	cls_IGESSolid_HArray1OfVertexList.def_static("get_type_name_", (const char * (*)()) &IGESSolid_HArray1OfVertexList::get_type_name, "None");
	cls_IGESSolid_HArray1OfVertexList.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_HArray1OfVertexList::get_type_descriptor, "None");
	cls_IGESSolid_HArray1OfVertexList.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_HArray1OfVertexList::*)() const ) &IGESSolid_HArray1OfVertexList::DynamicType, "None");


}
