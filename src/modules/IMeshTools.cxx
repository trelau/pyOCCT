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
#include <IMeshData_Face.hxx>
#include <Standard_Transient.hxx>
#include <IMeshData_Types.hxx>
#include <IMeshTools_Parameters.hxx>
#include <Standard_Std.hxx>
#include <IMeshTools_MeshAlgo.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <Message_Algorithm.hxx>
#include <IMeshData_Model.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Failure.hxx>
#include <IMeshTools_ModelBuilder.hxx>
#include <IMeshTools_ModelAlgo.hxx>
#include <IMeshData_Shape.hxx>
#include <IMeshTools_Context.hxx>
#include <gp_Pnt.hxx>
#include <IMeshTools_CurveTessellator.hxx>
#include <GeomAbs_SurfaceType.hxx>
#include <IMeshTools_MeshAlgoFactory.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <IMeshTools_ShapeVisitor.hxx>
#include <IMeshTools_MeshBuilder.hxx>
#include <IMeshTools_ShapeExplorer.hxx>

PYBIND11_MODULE(IMeshTools, mod) {

py::module::import("OCCT.IMeshData");
py::module::import("OCCT.Standard");
py::module::import("OCCT.Message");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.gp");
py::module::import("OCCT.GeomAbs");

// CLASS: IMESHTOOLS_MESHALGO
py::class_<IMeshTools_MeshAlgo, opencascade::handle<IMeshTools_MeshAlgo>, Standard_Transient> cls_IMeshTools_MeshAlgo(mod, "IMeshTools_MeshAlgo", "Interface class providing API for algorithms intended to create mesh for discrete face.");

// Methods
cls_IMeshTools_MeshAlgo.def("Perform", (void (IMeshTools_MeshAlgo::*)(const IMeshData::IFaceHandle &, const IMeshTools_Parameters &)) &IMeshTools_MeshAlgo::Perform, "Performs processing of the given face.", py::arg("theDFace"), py::arg("theParameters"));
cls_IMeshTools_MeshAlgo.def_static("get_type_name_", (const char * (*)()) &IMeshTools_MeshAlgo::get_type_name, "None");
cls_IMeshTools_MeshAlgo.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IMeshTools_MeshAlgo::get_type_descriptor, "None");
cls_IMeshTools_MeshAlgo.def("DynamicType", (const opencascade::handle<Standard_Type> & (IMeshTools_MeshAlgo::*)() const) &IMeshTools_MeshAlgo::DynamicType, "None");

// CLASS: IMESHTOOLS_PARAMETERS
py::class_<IMeshTools_Parameters> cls_IMeshTools_Parameters(mod, "IMeshTools_Parameters", "Structure storing meshing parameters");

// Constructors
cls_IMeshTools_Parameters.def(py::init<>());

// Fields
cls_IMeshTools_Parameters.def_readwrite("Angle", &IMeshTools_Parameters::Angle, "Angular deflection used to tessellate the boundary edges");
cls_IMeshTools_Parameters.def_readwrite("Deflection", &IMeshTools_Parameters::Deflection, "Linear deflection used to tessellate the boundary edges");
cls_IMeshTools_Parameters.def_readwrite("AngleInterior", &IMeshTools_Parameters::AngleInterior, "Angular deflection used to tessellate the face interior");
cls_IMeshTools_Parameters.def_readwrite("DeflectionInterior", &IMeshTools_Parameters::DeflectionInterior, "Linear deflection used to tessellate the face interior");
cls_IMeshTools_Parameters.def_readwrite("MinSize", &IMeshTools_Parameters::MinSize, "Minimal allowed size of mesh element");
cls_IMeshTools_Parameters.def_readwrite("InParallel", &IMeshTools_Parameters::InParallel, "Switches on/off multi-thread computation");
cls_IMeshTools_Parameters.def_readwrite("Relative", &IMeshTools_Parameters::Relative, "Switches on/off relative computation of edge tolerance If true, deflection used for the polygonalisation of each edge will be <defle> * Size of Edge. The deflection used for the faces will be the maximum deflection of their edges.");
cls_IMeshTools_Parameters.def_readwrite("InternalVerticesMode", &IMeshTools_Parameters::InternalVerticesMode, "Mode to take or not to take internal face vertices into account in triangulation process");
cls_IMeshTools_Parameters.def_readwrite("ControlSurfaceDeflection", &IMeshTools_Parameters::ControlSurfaceDeflection, "Parameter to check the deviation of triangulation and interior of the face");
cls_IMeshTools_Parameters.def_readwrite("CleanModel", &IMeshTools_Parameters::CleanModel, "Cleans temporary data model when algorithm is finished.");
cls_IMeshTools_Parameters.def_readwrite("AdjustMinSize", &IMeshTools_Parameters::AdjustMinSize, "Enables/disables local adjustment of min size depending on edge size. Disabled by default.");

// Methods
cls_IMeshTools_Parameters.def_static("RelMinSize_", (Standard_Real (*)()) &IMeshTools_Parameters::RelMinSize, "Returns factor used to compute default value of MinSize (minimum mesh edge length) from deflection");

// CLASS: IMESHTOOLS_MODELBUILDER
py::class_<IMeshTools_ModelBuilder, opencascade::handle<IMeshTools_ModelBuilder>, Message_Algorithm> cls_IMeshTools_ModelBuilder(mod, "IMeshTools_ModelBuilder", "Interface class represents API for tool building discrete model.");

// Methods
cls_IMeshTools_ModelBuilder.def("Perform", (opencascade::handle<IMeshData_Model> (IMeshTools_ModelBuilder::*)(const TopoDS_Shape &, const IMeshTools_Parameters &)) &IMeshTools_ModelBuilder::Perform, "Exceptions protected method to create discrete model for the given shape. Returns nullptr in case of failure.", py::arg("theShape"), py::arg("theParameters"));
cls_IMeshTools_ModelBuilder.def_static("get_type_name_", (const char * (*)()) &IMeshTools_ModelBuilder::get_type_name, "None");
cls_IMeshTools_ModelBuilder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IMeshTools_ModelBuilder::get_type_descriptor, "None");
cls_IMeshTools_ModelBuilder.def("DynamicType", (const opencascade::handle<Standard_Type> & (IMeshTools_ModelBuilder::*)() const) &IMeshTools_ModelBuilder::DynamicType, "None");

// CLASS: IMESHTOOLS_MODELALGO
py::class_<IMeshTools_ModelAlgo, opencascade::handle<IMeshTools_ModelAlgo>, Standard_Transient> cls_IMeshTools_ModelAlgo(mod, "IMeshTools_ModelAlgo", "Interface class providing API for algorithms intended to update or modify discrete model.");

// Methods
cls_IMeshTools_ModelAlgo.def("Perform", (Standard_Boolean (IMeshTools_ModelAlgo::*)(const opencascade::handle<IMeshData_Model> &, const IMeshTools_Parameters &)) &IMeshTools_ModelAlgo::Perform, "Exceptions protected processing of the given model.", py::arg("theModel"), py::arg("theParameters"));
cls_IMeshTools_ModelAlgo.def_static("get_type_name_", (const char * (*)()) &IMeshTools_ModelAlgo::get_type_name, "None");
cls_IMeshTools_ModelAlgo.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IMeshTools_ModelAlgo::get_type_descriptor, "None");
cls_IMeshTools_ModelAlgo.def("DynamicType", (const opencascade::handle<Standard_Type> & (IMeshTools_ModelAlgo::*)() const) &IMeshTools_ModelAlgo::DynamicType, "None");

// CLASS: IMESHTOOLS_CONTEXT
py::class_<IMeshTools_Context, opencascade::handle<IMeshTools_Context>, IMeshData_Shape> cls_IMeshTools_Context(mod, "IMeshTools_Context", "Interface class representing context of BRepMesh algorithm. Intended to cache discrete model and instances of tools for its processing.");

// Constructors
cls_IMeshTools_Context.def(py::init<>());

// Methods
cls_IMeshTools_Context.def("BuildModel", (Standard_Boolean (IMeshTools_Context::*)()) &IMeshTools_Context::BuildModel, "Builds model using assined model builder.");
cls_IMeshTools_Context.def("DiscretizeEdges", (Standard_Boolean (IMeshTools_Context::*)()) &IMeshTools_Context::DiscretizeEdges, "Performs discretization of model edges using assigned edge discret algorithm.");
cls_IMeshTools_Context.def("HealModel", (Standard_Boolean (IMeshTools_Context::*)()) &IMeshTools_Context::HealModel, "Performs healing of discrete model built by DiscretizeEdges() method using assigned healing algorithm.");
cls_IMeshTools_Context.def("PreProcessModel", (Standard_Boolean (IMeshTools_Context::*)()) &IMeshTools_Context::PreProcessModel, "Performs pre-processing of discrete model using assigned algorithm. Performs auxiliary actions such as cleaning shape from old triangulation.");
cls_IMeshTools_Context.def("DiscretizeFaces", (Standard_Boolean (IMeshTools_Context::*)()) &IMeshTools_Context::DiscretizeFaces, "Performs meshing of faces of discrete model using assigned meshing algorithm.");
cls_IMeshTools_Context.def("PostProcessModel", (Standard_Boolean (IMeshTools_Context::*)()) &IMeshTools_Context::PostProcessModel, "Performs post-processing of discrete model using assigned algorithm.");
cls_IMeshTools_Context.def("Clean", (void (IMeshTools_Context::*)()) &IMeshTools_Context::Clean, "Cleans temporary context data.");
cls_IMeshTools_Context.def("GetModelBuilder", (const opencascade::handle<IMeshTools_ModelBuilder> & (IMeshTools_Context::*)() const) &IMeshTools_Context::GetModelBuilder, "Gets instance of a tool to be used to build discrete model.");
cls_IMeshTools_Context.def("SetModelBuilder", (void (IMeshTools_Context::*)(const opencascade::handle<IMeshTools_ModelBuilder> &)) &IMeshTools_Context::SetModelBuilder, "Sets instance of a tool to be used to build discrete model.", py::arg("theBuilder"));
cls_IMeshTools_Context.def("GetEdgeDiscret", (const opencascade::handle<IMeshTools_ModelAlgo> & (IMeshTools_Context::*)() const) &IMeshTools_Context::GetEdgeDiscret, "Gets instance of a tool to be used to discretize edges of a model.");
cls_IMeshTools_Context.def("SetEdgeDiscret", (void (IMeshTools_Context::*)(const opencascade::handle<IMeshTools_ModelAlgo> &)) &IMeshTools_Context::SetEdgeDiscret, "Sets instance of a tool to be used to discretize edges of a model.", py::arg("theEdgeDiscret"));
cls_IMeshTools_Context.def("GetModelHealer", (const opencascade::handle<IMeshTools_ModelAlgo> & (IMeshTools_Context::*)() const) &IMeshTools_Context::GetModelHealer, "Gets instance of a tool to be used to heal discrete model.");
cls_IMeshTools_Context.def("SetModelHealer", (void (IMeshTools_Context::*)(const opencascade::handle<IMeshTools_ModelAlgo> &)) &IMeshTools_Context::SetModelHealer, "Sets instance of a tool to be used to heal discrete model.", py::arg("theModelHealer"));
cls_IMeshTools_Context.def("GetPreProcessor", (const opencascade::handle<IMeshTools_ModelAlgo> & (IMeshTools_Context::*)() const) &IMeshTools_Context::GetPreProcessor, "Gets instance of pre-processing algorithm.");
cls_IMeshTools_Context.def("SetPreProcessor", (void (IMeshTools_Context::*)(const opencascade::handle<IMeshTools_ModelAlgo> &)) &IMeshTools_Context::SetPreProcessor, "Sets instance of pre-processing algorithm.", py::arg("thePreProcessor"));
cls_IMeshTools_Context.def("GetFaceDiscret", (const opencascade::handle<IMeshTools_ModelAlgo> & (IMeshTools_Context::*)() const) &IMeshTools_Context::GetFaceDiscret, "Gets instance of meshing algorithm.");
cls_IMeshTools_Context.def("SetFaceDiscret", (void (IMeshTools_Context::*)(const opencascade::handle<IMeshTools_ModelAlgo> &)) &IMeshTools_Context::SetFaceDiscret, "Sets instance of meshing algorithm.", py::arg("theFaceDiscret"));
cls_IMeshTools_Context.def("GetPostProcessor", (const opencascade::handle<IMeshTools_ModelAlgo> & (IMeshTools_Context::*)() const) &IMeshTools_Context::GetPostProcessor, "Gets instance of post-processing algorithm.");
cls_IMeshTools_Context.def("SetPostProcessor", (void (IMeshTools_Context::*)(const opencascade::handle<IMeshTools_ModelAlgo> &)) &IMeshTools_Context::SetPostProcessor, "Sets instance of post-processing algorithm.", py::arg("thePostProcessor"));
cls_IMeshTools_Context.def("GetParameters", (const IMeshTools_Parameters & (IMeshTools_Context::*)() const) &IMeshTools_Context::GetParameters, "Gets parameters to be used for meshing.");
cls_IMeshTools_Context.def("ChangeParameters", (IMeshTools_Parameters & (IMeshTools_Context::*)()) &IMeshTools_Context::ChangeParameters, "Gets reference to parameters to be used for meshing.");
cls_IMeshTools_Context.def("GetModel", (const opencascade::handle<IMeshData_Model> & (IMeshTools_Context::*)() const) &IMeshTools_Context::GetModel, "Returns discrete model of a shape.");
cls_IMeshTools_Context.def_static("get_type_name_", (const char * (*)()) &IMeshTools_Context::get_type_name, "None");
cls_IMeshTools_Context.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IMeshTools_Context::get_type_descriptor, "None");
cls_IMeshTools_Context.def("DynamicType", (const opencascade::handle<Standard_Type> & (IMeshTools_Context::*)() const) &IMeshTools_Context::DynamicType, "None");

// CLASS: IMESHTOOLS_CURVETESSELLATOR
py::class_<IMeshTools_CurveTessellator, opencascade::handle<IMeshTools_CurveTessellator>, Standard_Transient> cls_IMeshTools_CurveTessellator(mod, "IMeshTools_CurveTessellator", "Interface class providing API for edge tessellation tools.");

// Methods
cls_IMeshTools_CurveTessellator.def("PointsNb", (Standard_Integer (IMeshTools_CurveTessellator::*)() const) &IMeshTools_CurveTessellator::PointsNb, "Returns number of tessellation points.");
cls_IMeshTools_CurveTessellator.def("Value", [](IMeshTools_CurveTessellator &self, const Standard_Integer theIndex, gp_Pnt & thePoint, Standard_Real & theParameter){ Standard_Boolean rv = self.Value(theIndex, thePoint, theParameter); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theParameter); }, "Returns parameters of solution with the given index.", py::arg("theIndex"), py::arg("thePoint"), py::arg("theParameter"));
cls_IMeshTools_CurveTessellator.def_static("get_type_name_", (const char * (*)()) &IMeshTools_CurveTessellator::get_type_name, "None");
cls_IMeshTools_CurveTessellator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IMeshTools_CurveTessellator::get_type_descriptor, "None");
cls_IMeshTools_CurveTessellator.def("DynamicType", (const opencascade::handle<Standard_Type> & (IMeshTools_CurveTessellator::*)() const) &IMeshTools_CurveTessellator::DynamicType, "None");

// CLASS: IMESHTOOLS_MESHALGOFACTORY
py::class_<IMeshTools_MeshAlgoFactory, opencascade::handle<IMeshTools_MeshAlgoFactory>, Standard_Transient> cls_IMeshTools_MeshAlgoFactory(mod, "IMeshTools_MeshAlgoFactory", "Base interface for factories producing instances of triangulation algorithms taking into account type of surface of target face.");

// Methods
cls_IMeshTools_MeshAlgoFactory.def("GetAlgo", (opencascade::handle<IMeshTools_MeshAlgo> (IMeshTools_MeshAlgoFactory::*)(const GeomAbs_SurfaceType, const IMeshTools_Parameters &) const) &IMeshTools_MeshAlgoFactory::GetAlgo, "Creates instance of meshing algorithm for the given type of surface.", py::arg("theSurfaceType"), py::arg("theParameters"));
cls_IMeshTools_MeshAlgoFactory.def_static("get_type_name_", (const char * (*)()) &IMeshTools_MeshAlgoFactory::get_type_name, "None");
cls_IMeshTools_MeshAlgoFactory.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IMeshTools_MeshAlgoFactory::get_type_descriptor, "None");
cls_IMeshTools_MeshAlgoFactory.def("DynamicType", (const opencascade::handle<Standard_Type> & (IMeshTools_MeshAlgoFactory::*)() const) &IMeshTools_MeshAlgoFactory::DynamicType, "None");

// CLASS: IMESHTOOLS_SHAPEVISITOR
py::class_<IMeshTools_ShapeVisitor, opencascade::handle<IMeshTools_ShapeVisitor>, Standard_Transient> cls_IMeshTools_ShapeVisitor(mod, "IMeshTools_ShapeVisitor", "Interface class for shape visitor.");

// Methods
cls_IMeshTools_ShapeVisitor.def("Visit", (void (IMeshTools_ShapeVisitor::*)(const TopoDS_Face &)) &IMeshTools_ShapeVisitor::Visit, "Handles TopoDS_Face object.", py::arg("theFace"));
cls_IMeshTools_ShapeVisitor.def("Visit", (void (IMeshTools_ShapeVisitor::*)(const TopoDS_Edge &)) &IMeshTools_ShapeVisitor::Visit, "Handles TopoDS_Edge object.", py::arg("theEdge"));
cls_IMeshTools_ShapeVisitor.def_static("get_type_name_", (const char * (*)()) &IMeshTools_ShapeVisitor::get_type_name, "None");
cls_IMeshTools_ShapeVisitor.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IMeshTools_ShapeVisitor::get_type_descriptor, "None");
cls_IMeshTools_ShapeVisitor.def("DynamicType", (const opencascade::handle<Standard_Type> & (IMeshTools_ShapeVisitor::*)() const) &IMeshTools_ShapeVisitor::DynamicType, "None");

// CLASS: IMESHTOOLS_MESHBUILDER
py::class_<IMeshTools_MeshBuilder, opencascade::handle<IMeshTools_MeshBuilder>, Message_Algorithm> cls_IMeshTools_MeshBuilder(mod, "IMeshTools_MeshBuilder", "Builds mesh for each face of shape without triangulation. In case if some faces of shape have already been triangulated checks deflection of existing polygonal model and re-uses it if deflection satisfies the specified parameter. Otherwise nullifies existing triangulation and build triangulation anew.");

// Constructors
cls_IMeshTools_MeshBuilder.def(py::init<>());
cls_IMeshTools_MeshBuilder.def(py::init<const opencascade::handle<IMeshTools_Context> &>(), py::arg("theContext"));

// Methods
cls_IMeshTools_MeshBuilder.def("SetContext", (void (IMeshTools_MeshBuilder::*)(const opencascade::handle<IMeshTools_Context> &)) &IMeshTools_MeshBuilder::SetContext, "Sets context for algorithm.", py::arg("theContext"));
cls_IMeshTools_MeshBuilder.def("GetContext", (const opencascade::handle<IMeshTools_Context> & (IMeshTools_MeshBuilder::*)() const) &IMeshTools_MeshBuilder::GetContext, "Gets context of algorithm.");
cls_IMeshTools_MeshBuilder.def("Perform", (void (IMeshTools_MeshBuilder::*)()) &IMeshTools_MeshBuilder::Perform, "Performs meshing ot the shape using current context.");
cls_IMeshTools_MeshBuilder.def_static("get_type_name_", (const char * (*)()) &IMeshTools_MeshBuilder::get_type_name, "None");
cls_IMeshTools_MeshBuilder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IMeshTools_MeshBuilder::get_type_descriptor, "None");
cls_IMeshTools_MeshBuilder.def("DynamicType", (const opencascade::handle<Standard_Type> & (IMeshTools_MeshBuilder::*)() const) &IMeshTools_MeshBuilder::DynamicType, "None");

// CLASS: IMESHTOOLS_SHAPEEXPLORER
py::class_<IMeshTools_ShapeExplorer, opencascade::handle<IMeshTools_ShapeExplorer>, IMeshData_Shape> cls_IMeshTools_ShapeExplorer(mod, "IMeshTools_ShapeExplorer", "Explores TopoDS_Shape for parts to be meshed - faces and free edges.");

// Constructors
cls_IMeshTools_ShapeExplorer.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));

// Methods
cls_IMeshTools_ShapeExplorer.def("Accept", (void (IMeshTools_ShapeExplorer::*)(const opencascade::handle<IMeshTools_ShapeVisitor> &)) &IMeshTools_ShapeExplorer::Accept, "Starts exploring of a shape.", py::arg("theVisitor"));
cls_IMeshTools_ShapeExplorer.def_static("get_type_name_", (const char * (*)()) &IMeshTools_ShapeExplorer::get_type_name, "None");
cls_IMeshTools_ShapeExplorer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IMeshTools_ShapeExplorer::get_type_descriptor, "None");
cls_IMeshTools_ShapeExplorer.def("DynamicType", (const opencascade::handle<Standard_Type> & (IMeshTools_ShapeExplorer::*)() const) &IMeshTools_ShapeExplorer::DynamicType, "None");


}
