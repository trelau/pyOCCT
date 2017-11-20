#include <pyOCCT_Common.hpp>

#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <IGESToBRep_IGESBoundary.hxx>
#include <Standard_Type.hxx>
#include <IGESToBRep_ToolContainer.hxx>
#include <IGESToBRep_AlgoContainer.hxx>
#include <IGESToBRep_CurveAndSurface.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESData_IGESModel.hxx>
#include <Transfer_TransientProcess.hxx>
#include <TopoDS_Shape.hxx>
#include <IGESData_IGESEntity.hxx>
#include <Message_Msg.hxx>
#include <Geom_Surface.hxx>
#include <TopoDS_Face.hxx>
#include <gp_Trsf2d.hxx>
#include <ShapeExtend_WireData.hxx>
#include <IGESData_HArray1OfIGESEntity.hxx>
#include <Geom_Plane.hxx>
#include <IGESSolid_PlaneSurface.hxx>
#include <Geom_CylindricalSurface.hxx>
#include <IGESSolid_CylindricalSurface.hxx>
#include <Geom_ConicalSurface.hxx>
#include <IGESSolid_ConicalSurface.hxx>
#include <Geom_SphericalSurface.hxx>
#include <IGESSolid_SphericalSurface.hxx>
#include <Geom_ToroidalSurface.hxx>
#include <IGESSolid_ToroidalSurface.hxx>
#include <Geom_BSplineSurface.hxx>
#include <IGESGeom_SplineSurface.hxx>
#include <IGESGeom_BSplineSurface.hxx>
#include <IGESToBRep_BasicSurface.hxx>
#include <Geom_Curve.hxx>
#include <Geom2d_Curve.hxx>
#include <IGESGeom_BSplineCurve.hxx>
#include <IGESGeom_CircularArc.hxx>
#include <IGESGeom_ConicArc.hxx>
#include <Geom_BSplineCurve.hxx>
#include <IGESGeom_CopiousData.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <IGESGeom_Line.hxx>
#include <IGESGeom_SplineCurve.hxx>
#include <Geom_Transformation.hxx>
#include <IGESGeom_TransformationMatrix.hxx>
#include <IGESToBRep_BasicCurve.hxx>
#include <IGESGeom_RuledSurface.hxx>
#include <IGESGeom_SurfaceOfRevolution.hxx>
#include <IGESGeom_TabulatedCylinder.hxx>
#include <IGESGeom_OffsetSurface.hxx>
#include <IGESGeom_TrimmedSurface.hxx>
#include <IGESGeom_BoundedSurface.hxx>
#include <IGESGeom_Plane.hxx>
#include <IGESBasic_SingleParent.hxx>
#include <IGESToBRep_TopoSurface.hxx>
#include <IGESToBRep_TopoCurve.hxx>
#include <TopoDS_Vertex.hxx>
#include <IGESGeom_Point.hxx>
#include <IGESGeom_CompositeCurve.hxx>
#include <IGESGeom_OffsetCurve.hxx>
#include <IGESGeom_CurveOnSurface.hxx>
#include <IGESGeom_Boundary.hxx>
#include <IGESSolid_VertexList.hxx>
#include <IGESSolid_EdgeList.hxx>
#include <IGESSolid_Loop.hxx>
#include <IGESSolid_Face.hxx>
#include <IGESSolid_Shell.hxx>
#include <IGESSolid_ManifoldSolid.hxx>
#include <IGESToBRep_BRepEntity.hxx>
#include <IGESToBRep_Actor.hxx>
#include <IGESToBRep_Reader.hxx>
#include <Transfer_ActorOfTransientProcess.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Transfer_Binder.hxx>
#include <TColStd_HSequenceOfTransient.hxx>
#include <TopoDS_Edge.hxx>
#include <IGESToBRep.hxx>

PYBIND11_MODULE(IGESToBRep, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.IGESData");
	py::module::import("OCCT.Transfer");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.Message");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.ShapeExtend");
	py::module::import("OCCT.IGESSolid");
	py::module::import("OCCT.IGESGeom");
	py::module::import("OCCT.Geom2d");
	py::module::import("OCCT.IGESBasic");
	py::module::import("OCCT.Interface");
	py::module::import("OCCT.TColStd");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESToBRep_ToolContainer.hxx
	py::class_<IGESToBRep_ToolContainer, opencascade::handle<IGESToBRep_ToolContainer>, Standard_Transient> cls_IGESToBRep_ToolContainer(mod, "IGESToBRep_ToolContainer", "None");
	cls_IGESToBRep_ToolContainer.def(py::init<>());
	cls_IGESToBRep_ToolContainer.def("IGESBoundary", (opencascade::handle<IGESToBRep_IGESBoundary> (IGESToBRep_ToolContainer::*)() const ) &IGESToBRep_ToolContainer::IGESBoundary, "Returns IGESToBRep_IGESBoundary");
	cls_IGESToBRep_ToolContainer.def_static("get_type_name_", (const char * (*)()) &IGESToBRep_ToolContainer::get_type_name, "None");
	cls_IGESToBRep_ToolContainer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESToBRep_ToolContainer::get_type_descriptor, "None");
	cls_IGESToBRep_ToolContainer.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESToBRep_ToolContainer::*)() const ) &IGESToBRep_ToolContainer::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESToBRep_AlgoContainer.hxx
	py::class_<IGESToBRep_AlgoContainer, opencascade::handle<IGESToBRep_AlgoContainer>, Standard_Transient> cls_IGESToBRep_AlgoContainer(mod, "IGESToBRep_AlgoContainer", "None");
	cls_IGESToBRep_AlgoContainer.def(py::init<>());
	cls_IGESToBRep_AlgoContainer.def("SetToolContainer", (void (IGESToBRep_AlgoContainer::*)(const opencascade::handle<IGESToBRep_ToolContainer> &)) &IGESToBRep_AlgoContainer::SetToolContainer, "Sets ToolContainer", py::arg("TC"));
	cls_IGESToBRep_AlgoContainer.def("ToolContainer", (opencascade::handle<IGESToBRep_ToolContainer> (IGESToBRep_AlgoContainer::*)() const ) &IGESToBRep_AlgoContainer::ToolContainer, "Returns ToolContainer");
	cls_IGESToBRep_AlgoContainer.def_static("get_type_name_", (const char * (*)()) &IGESToBRep_AlgoContainer::get_type_name, "None");
	cls_IGESToBRep_AlgoContainer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESToBRep_AlgoContainer::get_type_descriptor, "None");
	cls_IGESToBRep_AlgoContainer.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESToBRep_AlgoContainer::*)() const ) &IGESToBRep_AlgoContainer::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESToBRep_CurveAndSurface.hxx
	py::class_<IGESToBRep_CurveAndSurface, std::unique_ptr<IGESToBRep_CurveAndSurface, Deleter<IGESToBRep_CurveAndSurface>>> cls_IGESToBRep_CurveAndSurface(mod, "IGESToBRep_CurveAndSurface", "Provides methods to transfer CurveAndSurface from IGES to CASCADE.");
	cls_IGESToBRep_CurveAndSurface.def(py::init<>());
	cls_IGESToBRep_CurveAndSurface.def(py::init([] (const IGESToBRep_CurveAndSurface &other) {return new IGESToBRep_CurveAndSurface(other);}), "Copy constructor", py::arg("other"));
	cls_IGESToBRep_CurveAndSurface.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("eps"), py::arg("epsGeom"), py::arg("epsCoeff"), py::arg("mode"), py::arg("modeapprox"), py::arg("optimized"));
	cls_IGESToBRep_CurveAndSurface.def("Init", (void (IGESToBRep_CurveAndSurface::*)()) &IGESToBRep_CurveAndSurface::Init, "Initializes the field of the tool CurveAndSurface with default creating values.");
	cls_IGESToBRep_CurveAndSurface.def("SetEpsilon", (void (IGESToBRep_CurveAndSurface::*)(const Standard_Real)) &IGESToBRep_CurveAndSurface::SetEpsilon, "Changes the value of 'myEps'", py::arg("eps"));
	cls_IGESToBRep_CurveAndSurface.def("GetEpsilon", (Standard_Real (IGESToBRep_CurveAndSurface::*)() const ) &IGESToBRep_CurveAndSurface::GetEpsilon, "Returns the value of 'myEps'");
	cls_IGESToBRep_CurveAndSurface.def("SetEpsCoeff", (void (IGESToBRep_CurveAndSurface::*)(const Standard_Real)) &IGESToBRep_CurveAndSurface::SetEpsCoeff, "Changes the value of 'myEpsCoeff'", py::arg("eps"));
	cls_IGESToBRep_CurveAndSurface.def("GetEpsCoeff", (Standard_Real (IGESToBRep_CurveAndSurface::*)() const ) &IGESToBRep_CurveAndSurface::GetEpsCoeff, "Returns the value of 'myEpsCoeff'");
	cls_IGESToBRep_CurveAndSurface.def("SetEpsGeom", (void (IGESToBRep_CurveAndSurface::*)(const Standard_Real)) &IGESToBRep_CurveAndSurface::SetEpsGeom, "Changes the value of 'myEpsGeom'", py::arg("eps"));
	cls_IGESToBRep_CurveAndSurface.def("GetEpsGeom", (Standard_Real (IGESToBRep_CurveAndSurface::*)() const ) &IGESToBRep_CurveAndSurface::GetEpsGeom, "Returns the value of 'myEpsGeom'");
	cls_IGESToBRep_CurveAndSurface.def("SetMinTol", (void (IGESToBRep_CurveAndSurface::*)(const Standard_Real)) &IGESToBRep_CurveAndSurface::SetMinTol, "Changes the value of 'myMinTol'", py::arg("mintol"));
	cls_IGESToBRep_CurveAndSurface.def("SetMaxTol", (void (IGESToBRep_CurveAndSurface::*)(const Standard_Real)) &IGESToBRep_CurveAndSurface::SetMaxTol, "Changes the value of 'myMaxTol'", py::arg("maxtol"));
	cls_IGESToBRep_CurveAndSurface.def("UpdateMinMaxTol", (void (IGESToBRep_CurveAndSurface::*)()) &IGESToBRep_CurveAndSurface::UpdateMinMaxTol, "Sets values of 'myMinTol' and 'myMaxTol' as follows myMaxTol = Max ('read.maxprecision.val', myEpsGeom * myUnitFactor) myMinTol = Precision::Confusion() Remark: This method is automatically invoked each time the values of 'myEpsGeom' or 'myUnitFactor' are changed");
	cls_IGESToBRep_CurveAndSurface.def("GetMinTol", (Standard_Real (IGESToBRep_CurveAndSurface::*)() const ) &IGESToBRep_CurveAndSurface::GetMinTol, "Returns the value of 'myMinTol'");
	cls_IGESToBRep_CurveAndSurface.def("GetMaxTol", (Standard_Real (IGESToBRep_CurveAndSurface::*)() const ) &IGESToBRep_CurveAndSurface::GetMaxTol, "Returns the value of 'myMaxTol'");
	cls_IGESToBRep_CurveAndSurface.def("SetModeApprox", (void (IGESToBRep_CurveAndSurface::*)(const Standard_Boolean)) &IGESToBRep_CurveAndSurface::SetModeApprox, "Changes the value of 'myModeApprox'", py::arg("mode"));
	cls_IGESToBRep_CurveAndSurface.def("GetModeApprox", (Standard_Boolean (IGESToBRep_CurveAndSurface::*)() const ) &IGESToBRep_CurveAndSurface::GetModeApprox, "Returns the value of 'myModeApprox'");
	cls_IGESToBRep_CurveAndSurface.def("SetModeTransfer", (void (IGESToBRep_CurveAndSurface::*)(const Standard_Boolean)) &IGESToBRep_CurveAndSurface::SetModeTransfer, "Changes the value of 'myModeIsTopo'", py::arg("mode"));
	cls_IGESToBRep_CurveAndSurface.def("GetModeTransfer", (Standard_Boolean (IGESToBRep_CurveAndSurface::*)() const ) &IGESToBRep_CurveAndSurface::GetModeTransfer, "Returns the value of 'myModeIsTopo'");
	cls_IGESToBRep_CurveAndSurface.def("SetOptimized", (void (IGESToBRep_CurveAndSurface::*)(const Standard_Boolean)) &IGESToBRep_CurveAndSurface::SetOptimized, "Changes the value of 'myContIsOpti'", py::arg("optimized"));
	cls_IGESToBRep_CurveAndSurface.def("GetOptimized", (Standard_Boolean (IGESToBRep_CurveAndSurface::*)() const ) &IGESToBRep_CurveAndSurface::GetOptimized, "Returns the value of 'myContIsOpti'");
	cls_IGESToBRep_CurveAndSurface.def("GetUnitFactor", (Standard_Real (IGESToBRep_CurveAndSurface::*)() const ) &IGESToBRep_CurveAndSurface::GetUnitFactor, "Returns the value of ' myUnitFactor'");
	cls_IGESToBRep_CurveAndSurface.def("SetSurfaceCurve", (void (IGESToBRep_CurveAndSurface::*)(const Standard_Integer)) &IGESToBRep_CurveAndSurface::SetSurfaceCurve, "Changes the value of 'mySurfaceCurve'", py::arg("ival"));
	cls_IGESToBRep_CurveAndSurface.def("GetSurfaceCurve", (Standard_Integer (IGESToBRep_CurveAndSurface::*)() const ) &IGESToBRep_CurveAndSurface::GetSurfaceCurve, "Returns the value of ' mySurfaceCurve' 0 = value in file , 2 = kepp 2d and compute 3d 3 = keep 3d and compute 2d");
	cls_IGESToBRep_CurveAndSurface.def("SetModel", (void (IGESToBRep_CurveAndSurface::*)(const opencascade::handle<IGESData_IGESModel> &)) &IGESToBRep_CurveAndSurface::SetModel, "Set the value of 'myModel'", py::arg("model"));
	cls_IGESToBRep_CurveAndSurface.def("GetModel", (opencascade::handle<IGESData_IGESModel> (IGESToBRep_CurveAndSurface::*)() const ) &IGESToBRep_CurveAndSurface::GetModel, "Returns the value of 'myModel'");
	cls_IGESToBRep_CurveAndSurface.def("SetContinuity", (void (IGESToBRep_CurveAndSurface::*)(const Standard_Integer)) &IGESToBRep_CurveAndSurface::SetContinuity, "Changes the value of 'myContinuity' if continuity = 0 do nothing else if continuity = 1 try C1 if continuity = 2 try C2", py::arg("continuity"));
	cls_IGESToBRep_CurveAndSurface.def("GetContinuity", (Standard_Integer (IGESToBRep_CurveAndSurface::*)() const ) &IGESToBRep_CurveAndSurface::GetContinuity, "Returns the value of 'myContinuity'");
	cls_IGESToBRep_CurveAndSurface.def("SetTransferProcess", (void (IGESToBRep_CurveAndSurface::*)(const opencascade::handle<Transfer_TransientProcess> &)) &IGESToBRep_CurveAndSurface::SetTransferProcess, "Set the value of 'myMsgReg'", py::arg("TP"));
	cls_IGESToBRep_CurveAndSurface.def("GetTransferProcess", (opencascade::handle<Transfer_TransientProcess> (IGESToBRep_CurveAndSurface::*)() const ) &IGESToBRep_CurveAndSurface::GetTransferProcess, "Returns the value of 'myMsgReg'");
	cls_IGESToBRep_CurveAndSurface.def("TransferCurveAndSurface", (TopoDS_Shape (IGESToBRep_CurveAndSurface::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESToBRep_CurveAndSurface::TransferCurveAndSurface, "Returns the result of the transfert of any IGES Curve or Surface Entity. If the transfer has failed, this member return a NullEntity.", py::arg("start"));
	cls_IGESToBRep_CurveAndSurface.def("TransferGeometry", (TopoDS_Shape (IGESToBRep_CurveAndSurface::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESToBRep_CurveAndSurface::TransferGeometry, "Returns the result of the transfert the geometry of any IGESEntity. If the transfer has failed, this member return a NullEntity.", py::arg("start"));
	cls_IGESToBRep_CurveAndSurface.def("SendFail", (void (IGESToBRep_CurveAndSurface::*)(const opencascade::handle<IGESData_IGESEntity> &, const Message_Msg &)) &IGESToBRep_CurveAndSurface::SendFail, "Records a new Fail message", py::arg("start"), py::arg("amsg"));
	cls_IGESToBRep_CurveAndSurface.def("SendWarning", (void (IGESToBRep_CurveAndSurface::*)(const opencascade::handle<IGESData_IGESEntity> &, const Message_Msg &)) &IGESToBRep_CurveAndSurface::SendWarning, "Records a new Warning message", py::arg("start"), py::arg("amsg"));
	cls_IGESToBRep_CurveAndSurface.def("SendMsg", (void (IGESToBRep_CurveAndSurface::*)(const opencascade::handle<IGESData_IGESEntity> &, const Message_Msg &)) &IGESToBRep_CurveAndSurface::SendMsg, "Records a new Information message from the definition of a Msg (Original+Value)", py::arg("start"), py::arg("amsg"));
	cls_IGESToBRep_CurveAndSurface.def("HasShapeResult", (Standard_Boolean (IGESToBRep_CurveAndSurface::*)(const opencascade::handle<IGESData_IGESEntity> &) const ) &IGESToBRep_CurveAndSurface::HasShapeResult, "Returns True if start was already treated and has a result in 'myMap' else returns False.", py::arg("start"));
	cls_IGESToBRep_CurveAndSurface.def("GetShapeResult", (TopoDS_Shape (IGESToBRep_CurveAndSurface::*)(const opencascade::handle<IGESData_IGESEntity> &) const ) &IGESToBRep_CurveAndSurface::GetShapeResult, "Returns the result of the transfer of the IGESEntity 'start' contained in 'myMap' . (if HasShapeResult is True).", py::arg("start"));
	cls_IGESToBRep_CurveAndSurface.def("SetShapeResult", (void (IGESToBRep_CurveAndSurface::*)(const opencascade::handle<IGESData_IGESEntity> &, const TopoDS_Shape &)) &IGESToBRep_CurveAndSurface::SetShapeResult, "set in 'myMap' the result of the transfer of the IGESEntity 'start'.", py::arg("start"), py::arg("result"));
	cls_IGESToBRep_CurveAndSurface.def("NbShapeResult", (Standard_Integer (IGESToBRep_CurveAndSurface::*)(const opencascade::handle<IGESData_IGESEntity> &) const ) &IGESToBRep_CurveAndSurface::NbShapeResult, "Returns the number of shapes results contained in 'myMap' for the IGESEntity start ( type VertexList or EdgeList).", py::arg("start"));
	cls_IGESToBRep_CurveAndSurface.def("GetShapeResult", (TopoDS_Shape (IGESToBRep_CurveAndSurface::*)(const opencascade::handle<IGESData_IGESEntity> &, const Standard_Integer) const ) &IGESToBRep_CurveAndSurface::GetShapeResult, "Returns the numth result of the IGESEntity start (type VertexList or EdgeList) in 'myMap'. (if NbShapeResult is not null).", py::arg("start"), py::arg("num"));
	cls_IGESToBRep_CurveAndSurface.def("AddShapeResult", (void (IGESToBRep_CurveAndSurface::*)(const opencascade::handle<IGESData_IGESEntity> &, const TopoDS_Shape &)) &IGESToBRep_CurveAndSurface::AddShapeResult, "set in 'myMap' the result of the transfer of the entity of the IGESEntity start ( type VertexList or EdgeList).", py::arg("start"), py::arg("result"));
	cls_IGESToBRep_CurveAndSurface.def("SetSurface", (void (IGESToBRep_CurveAndSurface::*)(const opencascade::handle<Geom_Surface> &)) &IGESToBRep_CurveAndSurface::SetSurface, "None", py::arg("theSurface"));
	cls_IGESToBRep_CurveAndSurface.def("Surface", (opencascade::handle<Geom_Surface> (IGESToBRep_CurveAndSurface::*)() const ) &IGESToBRep_CurveAndSurface::Surface, "None");
	cls_IGESToBRep_CurveAndSurface.def("GetUVResolution", (Standard_Real (IGESToBRep_CurveAndSurface::*)()) &IGESToBRep_CurveAndSurface::GetUVResolution, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESToBRep_IGESBoundary.hxx
	py::class_<IGESToBRep_IGESBoundary, opencascade::handle<IGESToBRep_IGESBoundary>, Standard_Transient> cls_IGESToBRep_IGESBoundary(mod, "IGESToBRep_IGESBoundary", "This class is intended to translate IGES boundary entity (142-CurveOnSurface, 141-Boundary or 508-Loop) into the wire. Methods Transfer are virtual and are redefined in Advanced Data Exchange to optimize the translation and take into account advanced parameters.");
	cls_IGESToBRep_IGESBoundary.def(py::init<>());
	cls_IGESToBRep_IGESBoundary.def(py::init<const IGESToBRep_CurveAndSurface &>(), py::arg("CS"));
	cls_IGESToBRep_IGESBoundary.def("Init", (void (IGESToBRep_IGESBoundary::*)(const IGESToBRep_CurveAndSurface &, const opencascade::handle<IGESData_IGESEntity> &, const TopoDS_Face &, const gp_Trsf2d &, const Standard_Real, const Standard_Integer)) &IGESToBRep_IGESBoundary::Init, "Inits the object with parameters common for all types of IGES boundaries. <CS>: object to be used for retrieving translation parameters and sending messages, <entity>: boundary entity to be processed, <face>, <trans>, <uFact>: as for IGESToBRep_TopoCurve <filepreference>: preferred representation (2 or 3) given in the IGES file", py::arg("CS"), py::arg("entity"), py::arg("face"), py::arg("trans"), py::arg("uFact"), py::arg("filepreference"));
	cls_IGESToBRep_IGESBoundary.def("WireData", (opencascade::handle<ShapeExtend_WireData> (IGESToBRep_IGESBoundary::*)() const ) &IGESToBRep_IGESBoundary::WireData, "Returns the resulting wire");
	cls_IGESToBRep_IGESBoundary.def("WireData3d", (opencascade::handle<ShapeExtend_WireData> (IGESToBRep_IGESBoundary::*)() const ) &IGESToBRep_IGESBoundary::WireData3d, "Returns the wire from 3D curves (edges contain 3D curves and may contain pcurves)");
	cls_IGESToBRep_IGESBoundary.def("WireData2d", (opencascade::handle<ShapeExtend_WireData> (IGESToBRep_IGESBoundary::*)() const ) &IGESToBRep_IGESBoundary::WireData2d, "Returns the the wire from 2D curves (edges contain pcurves only)");
	cls_IGESToBRep_IGESBoundary.def("Transfer", [](IGESToBRep_IGESBoundary &self, Standard_Boolean & okCurve, Standard_Boolean & okCurve3d, Standard_Boolean & okCurve2d, const opencascade::handle<IGESData_IGESEntity> & curve3d, const Standard_Boolean toreverse3d, const opencascade::handle<IGESData_HArray1OfIGESEntity> & curves2d, const Standard_Integer number){ Standard_Boolean rv = self.Transfer(okCurve, okCurve3d, okCurve2d, curve3d, toreverse3d, curves2d, number); return std::tuple<Standard_Boolean, Standard_Boolean &, Standard_Boolean &, Standard_Boolean &>(rv, okCurve, okCurve3d, okCurve2d); }, "Translates 141 and 142 entities. Returns True if the curve has been successfully translated, otherwise returns False. <okCurve..>: flags that indicate whether corresponding representation has been successfully translated (must be set to True before first call), <curve3d>: model space curve for 142 and current model space curve for 141, <toreverse3d>: False for 142 and current orientation flag for 141, <curves2d>: 1 parameter space curve for 142 or list of them for current model space curves for 141, <number>: 1 for 142 and rank number of model space curve for 141.", py::arg("okCurve"), py::arg("okCurve3d"), py::arg("okCurve2d"), py::arg("curve3d"), py::arg("toreverse3d"), py::arg("curves2d"), py::arg("number"));
	cls_IGESToBRep_IGESBoundary.def("Transfer", [](IGESToBRep_IGESBoundary &self, Standard_Boolean & okCurve, Standard_Boolean & okCurve3d, Standard_Boolean & okCurve2d, const opencascade::handle<ShapeExtend_WireData> & curve3d, const opencascade::handle<IGESData_HArray1OfIGESEntity> & curves2d, const Standard_Boolean toreverse2d, const Standard_Integer number, opencascade::handle<ShapeExtend_WireData> & lsewd){ Standard_Boolean rv = self.Transfer(okCurve, okCurve3d, okCurve2d, curve3d, curves2d, toreverse2d, number, lsewd); return std::tuple<Standard_Boolean, Standard_Boolean &, Standard_Boolean &, Standard_Boolean &>(rv, okCurve, okCurve3d, okCurve2d); }, "Translates 508 entity. Returns True if the curve has been successfully translated, otherwise returns False. Input object IGESBoundary must be created and initialized before. <okCurve..>: flags that indicate whether corresponding representation has been successfully translated (must be set to True before first call), <curve3d>: result of translation of current edge, <curves2d>: list of parameter space curves for edge, <toreverse2d>: orientation flag of current edge in respect to its model space curve, <number>: rank number of edge, <lsewd>: returns the result of translation of current edge.", py::arg("okCurve"), py::arg("okCurve3d"), py::arg("okCurve2d"), py::arg("curve3d"), py::arg("curves2d"), py::arg("toreverse2d"), py::arg("number"), py::arg("lsewd"));
	cls_IGESToBRep_IGESBoundary.def("Check", (void (IGESToBRep_IGESBoundary::*)(const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &IGESToBRep_IGESBoundary::Check, "Checks result of translation of IGES boundary entities (types 141, 142 or 508). Checks consistency of 2D and 3D representations and keeps only one if they are inconsistent. <result>: result of translation (returned by Transfer), <checkclosure>: False for 142 without parent 144 entity, otherwise True, <okCurve3d>, <okCurve2d>: those returned by Transfer.", py::arg("result"), py::arg("checkclosure"), py::arg("okCurve3d"), py::arg("okCurve2d"));
	cls_IGESToBRep_IGESBoundary.def_static("get_type_name_", (const char * (*)()) &IGESToBRep_IGESBoundary::get_type_name, "None");
	cls_IGESToBRep_IGESBoundary.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESToBRep_IGESBoundary::get_type_descriptor, "None");
	cls_IGESToBRep_IGESBoundary.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESToBRep_IGESBoundary::*)() const ) &IGESToBRep_IGESBoundary::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESToBRep_BasicSurface.hxx
	py::class_<IGESToBRep_BasicSurface, std::unique_ptr<IGESToBRep_BasicSurface, Deleter<IGESToBRep_BasicSurface>>, IGESToBRep_CurveAndSurface> cls_IGESToBRep_BasicSurface(mod, "IGESToBRep_BasicSurface", "Provides methods to transfer basic geometric surface entities from IGES to CASCADE. These can be : * Spline surface * BSpline surface");
	cls_IGESToBRep_BasicSurface.def(py::init<>());
	cls_IGESToBRep_BasicSurface.def(py::init<const IGESToBRep_CurveAndSurface &>(), py::arg("CS"));
	cls_IGESToBRep_BasicSurface.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("eps"), py::arg("epsGeom"), py::arg("epsCoeff"), py::arg("mode"), py::arg("modeapprox"), py::arg("optimized"));
	cls_IGESToBRep_BasicSurface.def("TransferBasicSurface", (opencascade::handle<Geom_Surface> (IGESToBRep_BasicSurface::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESToBRep_BasicSurface::TransferBasicSurface, "Returns Surface from Geom if the last transfer has succeded.", py::arg("start"));
	cls_IGESToBRep_BasicSurface.def("TransferPlaneSurface", (opencascade::handle<Geom_Plane> (IGESToBRep_BasicSurface::*)(const opencascade::handle<IGESSolid_PlaneSurface> &)) &IGESToBRep_BasicSurface::TransferPlaneSurface, "Returns Plane from Geom if the transfer has succeded.", py::arg("start"));
	cls_IGESToBRep_BasicSurface.def("TransferRigthCylindricalSurface", (opencascade::handle<Geom_CylindricalSurface> (IGESToBRep_BasicSurface::*)(const opencascade::handle<IGESSolid_CylindricalSurface> &)) &IGESToBRep_BasicSurface::TransferRigthCylindricalSurface, "Returns CylindricalSurface from Geom if the transfer has succeded.", py::arg("start"));
	cls_IGESToBRep_BasicSurface.def("TransferRigthConicalSurface", (opencascade::handle<Geom_ConicalSurface> (IGESToBRep_BasicSurface::*)(const opencascade::handle<IGESSolid_ConicalSurface> &)) &IGESToBRep_BasicSurface::TransferRigthConicalSurface, "Returns ConicalSurface from Geom if the transfer has succeded.", py::arg("start"));
	cls_IGESToBRep_BasicSurface.def("TransferSphericalSurface", (opencascade::handle<Geom_SphericalSurface> (IGESToBRep_BasicSurface::*)(const opencascade::handle<IGESSolid_SphericalSurface> &)) &IGESToBRep_BasicSurface::TransferSphericalSurface, "Returns SphericalSurface from Geom if the transfer has succeded.", py::arg("start"));
	cls_IGESToBRep_BasicSurface.def("TransferToroidalSurface", (opencascade::handle<Geom_ToroidalSurface> (IGESToBRep_BasicSurface::*)(const opencascade::handle<IGESSolid_ToroidalSurface> &)) &IGESToBRep_BasicSurface::TransferToroidalSurface, "Returns SphericalSurface from Geom if the transfer has succeded.", py::arg("start"));
	cls_IGESToBRep_BasicSurface.def("TransferSplineSurface", (opencascade::handle<Geom_BSplineSurface> (IGESToBRep_BasicSurface::*)(const opencascade::handle<IGESGeom_SplineSurface> &)) &IGESToBRep_BasicSurface::TransferSplineSurface, "Returns BSplineSurface from Geom if the transfer has succeded.", py::arg("start"));
	cls_IGESToBRep_BasicSurface.def("TransferBSplineSurface", (opencascade::handle<Geom_BSplineSurface> (IGESToBRep_BasicSurface::*)(const opencascade::handle<IGESGeom_BSplineSurface> &)) &IGESToBRep_BasicSurface::TransferBSplineSurface, "Returns BSplineSurface from Geom if the transfer has succeded.", py::arg("start"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESToBRep_BasicCurve.hxx
	py::class_<IGESToBRep_BasicCurve, std::unique_ptr<IGESToBRep_BasicCurve, Deleter<IGESToBRep_BasicCurve>>, IGESToBRep_CurveAndSurface> cls_IGESToBRep_BasicCurve(mod, "IGESToBRep_BasicCurve", "Provides methods to transfer basic geometric curves entities from IGES to CASCADE. These can be : * Circular arc * Conic arc * Spline curve * BSpline curve * Line * Copious data * Point * Transformation matrix");
	cls_IGESToBRep_BasicCurve.def(py::init<>());
	cls_IGESToBRep_BasicCurve.def(py::init<const IGESToBRep_CurveAndSurface &>(), py::arg("CS"));
	cls_IGESToBRep_BasicCurve.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("eps"), py::arg("epsGeom"), py::arg("epsCoeff"), py::arg("mode"), py::arg("modeapprox"), py::arg("optimized"));
	cls_IGESToBRep_BasicCurve.def("TransferBasicCurve", (opencascade::handle<Geom_Curve> (IGESToBRep_BasicCurve::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESToBRep_BasicCurve::TransferBasicCurve, "Transfert a IGESEntity which answer True to the member : IGESToBRep::IsBasicCurve(IGESEntity). If this Entity could not be converted, this member returns a NullEntity.", py::arg("start"));
	cls_IGESToBRep_BasicCurve.def("Transfer2dBasicCurve", (opencascade::handle<Geom2d_Curve> (IGESToBRep_BasicCurve::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESToBRep_BasicCurve::Transfer2dBasicCurve, "Transfert a IGESEntity which answer True to the member : IGESToBRep::IsBasicCurve(IGESEntity). The IGESEntity must be a curve UV and its associed TRSF must be planar .If this Entity could not be converted, this member returns a NullEntity.", py::arg("start"));
	cls_IGESToBRep_BasicCurve.def("TransferBSplineCurve", (opencascade::handle<Geom_Curve> (IGESToBRep_BasicCurve::*)(const opencascade::handle<IGESGeom_BSplineCurve> &)) &IGESToBRep_BasicCurve::TransferBSplineCurve, "None", py::arg("start"));
	cls_IGESToBRep_BasicCurve.def("Transfer2dBSplineCurve", (opencascade::handle<Geom2d_Curve> (IGESToBRep_BasicCurve::*)(const opencascade::handle<IGESGeom_BSplineCurve> &)) &IGESToBRep_BasicCurve::Transfer2dBSplineCurve, "None", py::arg("start"));
	cls_IGESToBRep_BasicCurve.def("TransferCircularArc", (opencascade::handle<Geom_Curve> (IGESToBRep_BasicCurve::*)(const opencascade::handle<IGESGeom_CircularArc> &)) &IGESToBRep_BasicCurve::TransferCircularArc, "None", py::arg("start"));
	cls_IGESToBRep_BasicCurve.def("Transfer2dCircularArc", (opencascade::handle<Geom2d_Curve> (IGESToBRep_BasicCurve::*)(const opencascade::handle<IGESGeom_CircularArc> &)) &IGESToBRep_BasicCurve::Transfer2dCircularArc, "None", py::arg("start"));
	cls_IGESToBRep_BasicCurve.def("TransferConicArc", (opencascade::handle<Geom_Curve> (IGESToBRep_BasicCurve::*)(const opencascade::handle<IGESGeom_ConicArc> &)) &IGESToBRep_BasicCurve::TransferConicArc, "None", py::arg("start"));
	cls_IGESToBRep_BasicCurve.def("Transfer2dConicArc", (opencascade::handle<Geom2d_Curve> (IGESToBRep_BasicCurve::*)(const opencascade::handle<IGESGeom_ConicArc> &)) &IGESToBRep_BasicCurve::Transfer2dConicArc, "None", py::arg("start"));
	cls_IGESToBRep_BasicCurve.def("TransferCopiousData", (opencascade::handle<Geom_BSplineCurve> (IGESToBRep_BasicCurve::*)(const opencascade::handle<IGESGeom_CopiousData> &)) &IGESToBRep_BasicCurve::TransferCopiousData, "None", py::arg("start"));
	cls_IGESToBRep_BasicCurve.def("Transfer2dCopiousData", (opencascade::handle<Geom2d_BSplineCurve> (IGESToBRep_BasicCurve::*)(const opencascade::handle<IGESGeom_CopiousData> &)) &IGESToBRep_BasicCurve::Transfer2dCopiousData, "None", py::arg("start"));
	cls_IGESToBRep_BasicCurve.def("TransferLine", (opencascade::handle<Geom_Curve> (IGESToBRep_BasicCurve::*)(const opencascade::handle<IGESGeom_Line> &)) &IGESToBRep_BasicCurve::TransferLine, "None", py::arg("start"));
	cls_IGESToBRep_BasicCurve.def("Transfer2dLine", (opencascade::handle<Geom2d_Curve> (IGESToBRep_BasicCurve::*)(const opencascade::handle<IGESGeom_Line> &)) &IGESToBRep_BasicCurve::Transfer2dLine, "None", py::arg("start"));
	cls_IGESToBRep_BasicCurve.def("TransferSplineCurve", (opencascade::handle<Geom_BSplineCurve> (IGESToBRep_BasicCurve::*)(const opencascade::handle<IGESGeom_SplineCurve> &)) &IGESToBRep_BasicCurve::TransferSplineCurve, "None", py::arg("start"));
	cls_IGESToBRep_BasicCurve.def("Transfer2dSplineCurve", (opencascade::handle<Geom2d_BSplineCurve> (IGESToBRep_BasicCurve::*)(const opencascade::handle<IGESGeom_SplineCurve> &)) &IGESToBRep_BasicCurve::Transfer2dSplineCurve, "None", py::arg("start"));
	cls_IGESToBRep_BasicCurve.def("TransferTransformation", (opencascade::handle<Geom_Transformation> (IGESToBRep_BasicCurve::*)(const opencascade::handle<IGESGeom_TransformationMatrix> &)) &IGESToBRep_BasicCurve::TransferTransformation, "None", py::arg("start"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESToBRep_TopoSurface.hxx
	py::class_<IGESToBRep_TopoSurface, std::unique_ptr<IGESToBRep_TopoSurface, Deleter<IGESToBRep_TopoSurface>>, IGESToBRep_CurveAndSurface> cls_IGESToBRep_TopoSurface(mod, "IGESToBRep_TopoSurface", "Provides methods to transfer topologic surfaces entities from IGES to CASCADE.");
	cls_IGESToBRep_TopoSurface.def(py::init<>());
	cls_IGESToBRep_TopoSurface.def(py::init<const IGESToBRep_CurveAndSurface &>(), py::arg("CS"));
	cls_IGESToBRep_TopoSurface.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("eps"), py::arg("epsGeom"), py::arg("epsCoeff"), py::arg("mode"), py::arg("modeapprox"), py::arg("optimized"));
	cls_IGESToBRep_TopoSurface.def("TransferTopoSurface", (TopoDS_Shape (IGESToBRep_TopoSurface::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESToBRep_TopoSurface::TransferTopoSurface, "None", py::arg("start"));
	cls_IGESToBRep_TopoSurface.def("TransferTopoBasicSurface", (TopoDS_Shape (IGESToBRep_TopoSurface::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESToBRep_TopoSurface::TransferTopoBasicSurface, "None", py::arg("start"));
	cls_IGESToBRep_TopoSurface.def("TransferRuledSurface", (TopoDS_Shape (IGESToBRep_TopoSurface::*)(const opencascade::handle<IGESGeom_RuledSurface> &)) &IGESToBRep_TopoSurface::TransferRuledSurface, "None", py::arg("start"));
	cls_IGESToBRep_TopoSurface.def("TransferSurfaceOfRevolution", (TopoDS_Shape (IGESToBRep_TopoSurface::*)(const opencascade::handle<IGESGeom_SurfaceOfRevolution> &)) &IGESToBRep_TopoSurface::TransferSurfaceOfRevolution, "None", py::arg("start"));
	cls_IGESToBRep_TopoSurface.def("TransferTabulatedCylinder", (TopoDS_Shape (IGESToBRep_TopoSurface::*)(const opencascade::handle<IGESGeom_TabulatedCylinder> &)) &IGESToBRep_TopoSurface::TransferTabulatedCylinder, "None", py::arg("start"));
	cls_IGESToBRep_TopoSurface.def("TransferOffsetSurface", (TopoDS_Shape (IGESToBRep_TopoSurface::*)(const opencascade::handle<IGESGeom_OffsetSurface> &)) &IGESToBRep_TopoSurface::TransferOffsetSurface, "None", py::arg("start"));
	cls_IGESToBRep_TopoSurface.def("TransferTrimmedSurface", (TopoDS_Shape (IGESToBRep_TopoSurface::*)(const opencascade::handle<IGESGeom_TrimmedSurface> &)) &IGESToBRep_TopoSurface::TransferTrimmedSurface, "None", py::arg("start"));
	cls_IGESToBRep_TopoSurface.def("TransferBoundedSurface", (TopoDS_Shape (IGESToBRep_TopoSurface::*)(const opencascade::handle<IGESGeom_BoundedSurface> &)) &IGESToBRep_TopoSurface::TransferBoundedSurface, "None", py::arg("start"));
	cls_IGESToBRep_TopoSurface.def("TransferPlane", (TopoDS_Shape (IGESToBRep_TopoSurface::*)(const opencascade::handle<IGESGeom_Plane> &)) &IGESToBRep_TopoSurface::TransferPlane, "None", py::arg("start"));
	cls_IGESToBRep_TopoSurface.def("TransferPlaneSurface", (TopoDS_Shape (IGESToBRep_TopoSurface::*)(const opencascade::handle<IGESSolid_PlaneSurface> &)) &IGESToBRep_TopoSurface::TransferPlaneSurface, "None", py::arg("start"));
	cls_IGESToBRep_TopoSurface.def("TransferPerforate", (TopoDS_Shape (IGESToBRep_TopoSurface::*)(const opencascade::handle<IGESBasic_SingleParent> &)) &IGESToBRep_TopoSurface::TransferPerforate, "None", py::arg("start"));
	cls_IGESToBRep_TopoSurface.def("ParamSurface", [](IGESToBRep_TopoSurface &self, const opencascade::handle<IGESData_IGESEntity> & start, gp_Trsf2d & trans, Standard_Real & uFact){ TopoDS_Shape rv = self.ParamSurface(start, trans, uFact); return std::tuple<TopoDS_Shape, Standard_Real &>(rv, uFact); }, "None", py::arg("start"), py::arg("trans"), py::arg("uFact"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESToBRep_TopoCurve.hxx
	py::class_<IGESToBRep_TopoCurve, std::unique_ptr<IGESToBRep_TopoCurve, Deleter<IGESToBRep_TopoCurve>>, IGESToBRep_CurveAndSurface> cls_IGESToBRep_TopoCurve(mod, "IGESToBRep_TopoCurve", "Provides methods to transfer topologic curves entities from IGES to CASCADE.");
	cls_IGESToBRep_TopoCurve.def(py::init<>());
	cls_IGESToBRep_TopoCurve.def(py::init<const IGESToBRep_CurveAndSurface &>(), py::arg("CS"));
	cls_IGESToBRep_TopoCurve.def(py::init([] (const IGESToBRep_TopoCurve &other) {return new IGESToBRep_TopoCurve(other);}), "Copy constructor", py::arg("other"));
	cls_IGESToBRep_TopoCurve.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("eps"), py::arg("epsGeom"), py::arg("epsCoeff"), py::arg("mode"), py::arg("modeapprox"), py::arg("optimized"));
	cls_IGESToBRep_TopoCurve.def("TransferTopoCurve", (TopoDS_Shape (IGESToBRep_TopoCurve::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESToBRep_TopoCurve::TransferTopoCurve, "None", py::arg("start"));
	cls_IGESToBRep_TopoCurve.def("Transfer2dTopoCurve", (TopoDS_Shape (IGESToBRep_TopoCurve::*)(const opencascade::handle<IGESData_IGESEntity> &, const TopoDS_Face &, const gp_Trsf2d &, const Standard_Real)) &IGESToBRep_TopoCurve::Transfer2dTopoCurve, "None", py::arg("start"), py::arg("face"), py::arg("trans"), py::arg("uFact"));
	cls_IGESToBRep_TopoCurve.def("TransferTopoBasicCurve", (TopoDS_Shape (IGESToBRep_TopoCurve::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESToBRep_TopoCurve::TransferTopoBasicCurve, "None", py::arg("start"));
	cls_IGESToBRep_TopoCurve.def("Transfer2dTopoBasicCurve", (TopoDS_Shape (IGESToBRep_TopoCurve::*)(const opencascade::handle<IGESData_IGESEntity> &, const TopoDS_Face &, const gp_Trsf2d &, const Standard_Real)) &IGESToBRep_TopoCurve::Transfer2dTopoBasicCurve, "None", py::arg("start"), py::arg("face"), py::arg("trans"), py::arg("uFact"));
	cls_IGESToBRep_TopoCurve.def("TransferPoint", (TopoDS_Vertex (IGESToBRep_TopoCurve::*)(const opencascade::handle<IGESGeom_Point> &)) &IGESToBRep_TopoCurve::TransferPoint, "None", py::arg("start"));
	cls_IGESToBRep_TopoCurve.def("Transfer2dPoint", (TopoDS_Vertex (IGESToBRep_TopoCurve::*)(const opencascade::handle<IGESGeom_Point> &)) &IGESToBRep_TopoCurve::Transfer2dPoint, "None", py::arg("start"));
	cls_IGESToBRep_TopoCurve.def("TransferCompositeCurve", (TopoDS_Shape (IGESToBRep_TopoCurve::*)(const opencascade::handle<IGESGeom_CompositeCurve> &)) &IGESToBRep_TopoCurve::TransferCompositeCurve, "None", py::arg("start"));
	cls_IGESToBRep_TopoCurve.def("Transfer2dCompositeCurve", (TopoDS_Shape (IGESToBRep_TopoCurve::*)(const opencascade::handle<IGESGeom_CompositeCurve> &, const TopoDS_Face &, const gp_Trsf2d &, const Standard_Real)) &IGESToBRep_TopoCurve::Transfer2dCompositeCurve, "None", py::arg("start"), py::arg("face"), py::arg("trans"), py::arg("uFact"));
	cls_IGESToBRep_TopoCurve.def("TransferOffsetCurve", (TopoDS_Shape (IGESToBRep_TopoCurve::*)(const opencascade::handle<IGESGeom_OffsetCurve> &)) &IGESToBRep_TopoCurve::TransferOffsetCurve, "None", py::arg("start"));
	cls_IGESToBRep_TopoCurve.def("Transfer2dOffsetCurve", (TopoDS_Shape (IGESToBRep_TopoCurve::*)(const opencascade::handle<IGESGeom_OffsetCurve> &, const TopoDS_Face &, const gp_Trsf2d &, const Standard_Real)) &IGESToBRep_TopoCurve::Transfer2dOffsetCurve, "None", py::arg("start"), py::arg("face"), py::arg("trans"), py::arg("uFact"));
	cls_IGESToBRep_TopoCurve.def("TransferCurveOnSurface", (TopoDS_Shape (IGESToBRep_TopoCurve::*)(const opencascade::handle<IGESGeom_CurveOnSurface> &)) &IGESToBRep_TopoCurve::TransferCurveOnSurface, "None", py::arg("start"));
	cls_IGESToBRep_TopoCurve.def("TransferCurveOnFace", (TopoDS_Shape (IGESToBRep_TopoCurve::*)(TopoDS_Face &, const opencascade::handle<IGESGeom_CurveOnSurface> &, const gp_Trsf2d &, const Standard_Real, const Standard_Boolean)) &IGESToBRep_TopoCurve::TransferCurveOnFace, "Transfers a CurveOnSurface directly on a face to trim it. The CurveOnSurface have to be defined Outer or Inner.", py::arg("face"), py::arg("start"), py::arg("trans"), py::arg("uFact"), py::arg("IsCurv"));
	cls_IGESToBRep_TopoCurve.def("TransferBoundary", (TopoDS_Shape (IGESToBRep_TopoCurve::*)(const opencascade::handle<IGESGeom_Boundary> &)) &IGESToBRep_TopoCurve::TransferBoundary, "None", py::arg("start"));
	cls_IGESToBRep_TopoCurve.def("TransferBoundaryOnFace", (TopoDS_Shape (IGESToBRep_TopoCurve::*)(TopoDS_Face &, const opencascade::handle<IGESGeom_Boundary> &, const gp_Trsf2d &, const Standard_Real)) &IGESToBRep_TopoCurve::TransferBoundaryOnFace, "Transfers a Boundary directly on a face to trim it.", py::arg("face"), py::arg("start"), py::arg("trans"), py::arg("uFact"));
	cls_IGESToBRep_TopoCurve.def("ApproxBSplineCurve", (void (IGESToBRep_TopoCurve::*)(const opencascade::handle<Geom_BSplineCurve> &)) &IGESToBRep_TopoCurve::ApproxBSplineCurve, "None", py::arg("start"));
	cls_IGESToBRep_TopoCurve.def("NbCurves", (Standard_Integer (IGESToBRep_TopoCurve::*)() const ) &IGESToBRep_TopoCurve::NbCurves, "Returns the count of Curves in 'TheCurves'");
	cls_IGESToBRep_TopoCurve.def("Curve", [](IGESToBRep_TopoCurve &self) -> opencascade::handle<Geom_Curve> { return self.Curve(); });
	cls_IGESToBRep_TopoCurve.def("Curve", (opencascade::handle<Geom_Curve> (IGESToBRep_TopoCurve::*)(const Standard_Integer) const ) &IGESToBRep_TopoCurve::Curve, "Returns a Curve given its rank, by default the first one (null Curvee if out of range) in 'TheCurves'", py::arg("num"));
	cls_IGESToBRep_TopoCurve.def("Approx2dBSplineCurve", (void (IGESToBRep_TopoCurve::*)(const opencascade::handle<Geom2d_BSplineCurve> &)) &IGESToBRep_TopoCurve::Approx2dBSplineCurve, "None", py::arg("start"));
	cls_IGESToBRep_TopoCurve.def("NbCurves2d", (Standard_Integer (IGESToBRep_TopoCurve::*)() const ) &IGESToBRep_TopoCurve::NbCurves2d, "Returns the count of Curves in 'TheCurves2d'");
	cls_IGESToBRep_TopoCurve.def("Curve2d", [](IGESToBRep_TopoCurve &self) -> opencascade::handle<Geom2d_Curve> { return self.Curve2d(); });
	cls_IGESToBRep_TopoCurve.def("Curve2d", (opencascade::handle<Geom2d_Curve> (IGESToBRep_TopoCurve::*)(const Standard_Integer) const ) &IGESToBRep_TopoCurve::Curve2d, "Returns a Curve given its rank, by default the first one (null Curvee if out of range) in 'TheCurves2d'", py::arg("num"));
	cls_IGESToBRep_TopoCurve.def("SetBadCase", (void (IGESToBRep_TopoCurve::*)(const Standard_Boolean)) &IGESToBRep_TopoCurve::SetBadCase, "Sets TheBadCase flag", py::arg("value"));
	cls_IGESToBRep_TopoCurve.def("BadCase", (Standard_Boolean (IGESToBRep_TopoCurve::*)() const ) &IGESToBRep_TopoCurve::BadCase, "Returns TheBadCase flag");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESToBRep_BRepEntity.hxx
	py::class_<IGESToBRep_BRepEntity, std::unique_ptr<IGESToBRep_BRepEntity, Deleter<IGESToBRep_BRepEntity>>, IGESToBRep_CurveAndSurface> cls_IGESToBRep_BRepEntity(mod, "IGESToBRep_BRepEntity", "Provides methods to transfer BRep entities ( VertexList 502, EdgeList 504, Loop 508, Face 510, Shell 514, ManifoldSolid 186) from IGES to CASCADE.");
	cls_IGESToBRep_BRepEntity.def(py::init<>());
	cls_IGESToBRep_BRepEntity.def(py::init<const IGESToBRep_CurveAndSurface &>(), py::arg("CS"));
	cls_IGESToBRep_BRepEntity.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("eps"), py::arg("epsGeom"), py::arg("epsCoeff"), py::arg("mode"), py::arg("modeapprox"), py::arg("optimized"));
	cls_IGESToBRep_BRepEntity.def("TransferBRepEntity", (TopoDS_Shape (IGESToBRep_BRepEntity::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESToBRep_BRepEntity::TransferBRepEntity, "Transfer the BRepEntity' : Face, Shell or ManifoldSolid.", py::arg("start"));
	cls_IGESToBRep_BRepEntity.def("TransferVertex", (TopoDS_Vertex (IGESToBRep_BRepEntity::*)(const opencascade::handle<IGESSolid_VertexList> &, const Standard_Integer)) &IGESToBRep_BRepEntity::TransferVertex, "Transfer the entity number 'index' of the VertexList 'start'", py::arg("start"), py::arg("index"));
	cls_IGESToBRep_BRepEntity.def("TransferEdge", (TopoDS_Shape (IGESToBRep_BRepEntity::*)(const opencascade::handle<IGESSolid_EdgeList> &, const Standard_Integer)) &IGESToBRep_BRepEntity::TransferEdge, "Transfer the entity number 'index' of the EdgeList 'start'.", py::arg("start"), py::arg("index"));
	cls_IGESToBRep_BRepEntity.def("TransferLoop", (TopoDS_Shape (IGESToBRep_BRepEntity::*)(const opencascade::handle<IGESSolid_Loop> &, const TopoDS_Face &, const gp_Trsf2d &, const Standard_Real)) &IGESToBRep_BRepEntity::TransferLoop, "Transfer the Loop Entity", py::arg("start"), py::arg("Face"), py::arg("trans"), py::arg("uFact"));
	cls_IGESToBRep_BRepEntity.def("TransferFace", (TopoDS_Shape (IGESToBRep_BRepEntity::*)(const opencascade::handle<IGESSolid_Face> &)) &IGESToBRep_BRepEntity::TransferFace, "Transfer the Face Entity", py::arg("start"));
	cls_IGESToBRep_BRepEntity.def("TransferShell", (TopoDS_Shape (IGESToBRep_BRepEntity::*)(const opencascade::handle<IGESSolid_Shell> &)) &IGESToBRep_BRepEntity::TransferShell, "Transfer the Shell Entity", py::arg("start"));
	cls_IGESToBRep_BRepEntity.def("TransferManifoldSolid", (TopoDS_Shape (IGESToBRep_BRepEntity::*)(const opencascade::handle<IGESSolid_ManifoldSolid> &)) &IGESToBRep_BRepEntity::TransferManifoldSolid, "Transfer the ManifoldSolid Entity", py::arg("start"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESToBRep_Reader.hxx
	py::class_<IGESToBRep_Reader, std::unique_ptr<IGESToBRep_Reader, Deleter<IGESToBRep_Reader>>> cls_IGESToBRep_Reader(mod, "IGESToBRep_Reader", "A simple way to read geometric IGES data. Encapsulates reading file and calling transfer tools");
	cls_IGESToBRep_Reader.def(py::init<>());
	cls_IGESToBRep_Reader.def("LoadFile", (Standard_Integer (IGESToBRep_Reader::*)(const Standard_CString)) &IGESToBRep_Reader::LoadFile, "Loads a Model from a file.Returns 0 if success. returns 1 if the file could not be opened, returns -1 if an error occurred while the file was being loaded.", py::arg("filename"));
	cls_IGESToBRep_Reader.def("SetModel", (void (IGESToBRep_Reader::*)(const opencascade::handle<IGESData_IGESModel> &)) &IGESToBRep_Reader::SetModel, "Specifies a Model to work on Also clears the result and Done status, sets TransientProcess", py::arg("model"));
	cls_IGESToBRep_Reader.def("Model", (opencascade::handle<IGESData_IGESModel> (IGESToBRep_Reader::*)() const ) &IGESToBRep_Reader::Model, "Returns the Model to be worked on.");
	cls_IGESToBRep_Reader.def("SetTransientProcess", (void (IGESToBRep_Reader::*)(const opencascade::handle<Transfer_TransientProcess> &)) &IGESToBRep_Reader::SetTransientProcess, "Allows to set an already defined TransientProcess (to be called after LoadFile or SetModel)", py::arg("TP"));
	cls_IGESToBRep_Reader.def("TransientProcess", (opencascade::handle<Transfer_TransientProcess> (IGESToBRep_Reader::*)() const ) &IGESToBRep_Reader::TransientProcess, "Returns the TransientProcess");
	cls_IGESToBRep_Reader.def("Actor", (opencascade::handle<IGESToBRep_Actor> (IGESToBRep_Reader::*)() const ) &IGESToBRep_Reader::Actor, "Returns 'theActor'");
	cls_IGESToBRep_Reader.def("Clear", (void (IGESToBRep_Reader::*)()) &IGESToBRep_Reader::Clear, "Clears the results between two translation operations.");
	cls_IGESToBRep_Reader.def("Check", (Standard_Boolean (IGESToBRep_Reader::*)(const Standard_Boolean) const ) &IGESToBRep_Reader::Check, "Checks the IGES file that was loaded into memory. Displays error messages in the default message file if withprint is true. Returns True if no fail message was found and False if there was at least one fail message.", py::arg("withprint"));
	cls_IGESToBRep_Reader.def("TransferRoots", [](IGESToBRep_Reader &self) -> void { return self.TransferRoots(); });
	cls_IGESToBRep_Reader.def("TransferRoots", (void (IGESToBRep_Reader::*)(const Standard_Boolean)) &IGESToBRep_Reader::TransferRoots, "Translates root entities in an IGES file. Standard_True is the default value and means that only visible root entities are translated. Standard_False translates all of the roots (visible and invisible).", py::arg("onlyvisible"));
	cls_IGESToBRep_Reader.def("Transfer", (Standard_Boolean (IGESToBRep_Reader::*)(const Standard_Integer)) &IGESToBRep_Reader::Transfer, "Transfers an Entity given its rank in the Model (Root or not) Returns True if it is recognized as Geom-Topol. (But it can have failed : see IsDone)", py::arg("num"));
	cls_IGESToBRep_Reader.def("IsDone", (Standard_Boolean (IGESToBRep_Reader::*)() const ) &IGESToBRep_Reader::IsDone, "Returns True if the LAST Transfer/TransferRoots was a success");
	cls_IGESToBRep_Reader.def("UsedTolerance", (Standard_Real (IGESToBRep_Reader::*)() const ) &IGESToBRep_Reader::UsedTolerance, "Returns the Tolerance which has been actually used, converted in millimeters (either that from File or that from Session, according the mode)");
	cls_IGESToBRep_Reader.def("NbShapes", (Standard_Integer (IGESToBRep_Reader::*)() const ) &IGESToBRep_Reader::NbShapes, "Returns the number of shapes produced by the translation.");
	cls_IGESToBRep_Reader.def("Shape", [](IGESToBRep_Reader &self) -> TopoDS_Shape { return self.Shape(); });
	cls_IGESToBRep_Reader.def("Shape", (TopoDS_Shape (IGESToBRep_Reader::*)(const Standard_Integer) const ) &IGESToBRep_Reader::Shape, "Returns the num the resulting shape in a translation operation.", py::arg("num"));
	cls_IGESToBRep_Reader.def("OneShape", (TopoDS_Shape (IGESToBRep_Reader::*)() const ) &IGESToBRep_Reader::OneShape, "Returns all of the results in a single shape which is: - a null shape if there are no results, - a shape if there is one result, - a compound containing the resulting shapes if there are several.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESToBRep_Actor.hxx
	py::class_<IGESToBRep_Actor, opencascade::handle<IGESToBRep_Actor>, Transfer_ActorOfTransientProcess> cls_IGESToBRep_Actor(mod, "IGESToBRep_Actor", "This class performs the transfer of an Entity from IGESToBRep");
	cls_IGESToBRep_Actor.def(py::init<>());
	cls_IGESToBRep_Actor.def("SetModel", (void (IGESToBRep_Actor::*)(const opencascade::handle<Interface_InterfaceModel> &)) &IGESToBRep_Actor::SetModel, "None", py::arg("model"));
	cls_IGESToBRep_Actor.def("SetContinuity", [](IGESToBRep_Actor &self) -> void { return self.SetContinuity(); });
	cls_IGESToBRep_Actor.def("SetContinuity", (void (IGESToBRep_Actor::*)(const Standard_Integer)) &IGESToBRep_Actor::SetContinuity, "---Purpose By default continuity = 0 if continuity = 1 : try C1 if continuity = 2 : try C2", py::arg("continuity"));
	cls_IGESToBRep_Actor.def("GetContinuity", (Standard_Integer (IGESToBRep_Actor::*)() const ) &IGESToBRep_Actor::GetContinuity, "Return 'thecontinuity'");
	cls_IGESToBRep_Actor.def("Recognize", (Standard_Boolean (IGESToBRep_Actor::*)(const opencascade::handle<Standard_Transient> &)) &IGESToBRep_Actor::Recognize, "None", py::arg("start"));
	cls_IGESToBRep_Actor.def("Transfer", (opencascade::handle<Transfer_Binder> (IGESToBRep_Actor::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Transfer_TransientProcess> &)) &IGESToBRep_Actor::Transfer, "None", py::arg("start"), py::arg("TP"));
	cls_IGESToBRep_Actor.def("UsedTolerance", (Standard_Real (IGESToBRep_Actor::*)() const ) &IGESToBRep_Actor::UsedTolerance, "Returns the tolerance which was actually used, either from the file or from statics");
	cls_IGESToBRep_Actor.def_static("get_type_name_", (const char * (*)()) &IGESToBRep_Actor::get_type_name, "None");
	cls_IGESToBRep_Actor.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESToBRep_Actor::get_type_descriptor, "None");
	cls_IGESToBRep_Actor.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESToBRep_Actor::*)() const ) &IGESToBRep_Actor::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESToBRep.hxx
	py::class_<IGESToBRep, std::unique_ptr<IGESToBRep, Deleter<IGESToBRep>>> cls_IGESToBRep(mod, "IGESToBRep", "Provides tools in order to transfer IGES entities to CAS.CADE.");
	cls_IGESToBRep.def(py::init<>());
	cls_IGESToBRep.def_static("Init_", (void (*)()) &IGESToBRep::Init, "Creates and initializes default AlgoContainer.");
	cls_IGESToBRep.def_static("SetAlgoContainer_", (void (*)(const opencascade::handle<IGESToBRep_AlgoContainer> &)) &IGESToBRep::SetAlgoContainer, "Sets default AlgoContainer", py::arg("aContainer"));
	cls_IGESToBRep.def_static("AlgoContainer_", (opencascade::handle<IGESToBRep_AlgoContainer> (*)()) &IGESToBRep::AlgoContainer, "Returns default AlgoContainer");
	cls_IGESToBRep.def_static("IsCurveAndSurface_", (Standard_Boolean (*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESToBRep::IsCurveAndSurface, "Return True if the IGESEntity can be transfered by TransferCurveAndSurface. ex: All IGESEntity from IGESGeom", py::arg("start"));
	cls_IGESToBRep.def_static("IsBasicCurve_", (Standard_Boolean (*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESToBRep::IsBasicCurve, "Return True if the IGESEntity can be transfered by TransferBasicCurve. ex: CircularArc, ConicArc, Line, CopiousData, BSplineCurve, SplineCurve... from IGESGeom : 104,110,112,126", py::arg("start"));
	cls_IGESToBRep.def_static("IsBasicSurface_", (Standard_Boolean (*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESToBRep::IsBasicSurface, "Return True if the IGESEntity can be transfered by TransferBasicSurface. ex: BSplineSurface, SplineSurface... from IGESGeom : 114,128", py::arg("start"));
	cls_IGESToBRep.def_static("IsTopoCurve_", (Standard_Boolean (*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESToBRep::IsTopoCurve, "Return True if the IGESEntity can be transfered by TransferTopoCurve. ex: all Curves from IGESGeom : all basic curves,102,130,142,144", py::arg("start"));
	cls_IGESToBRep.def_static("IsTopoSurface_", (Standard_Boolean (*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESToBRep::IsTopoSurface, "Return True if the IGESEntity can be transfered by TransferTopoSurface. ex: All Surfaces from IGESGeom : all basic surfaces,108,118,120,122,141,143", py::arg("start"));
	cls_IGESToBRep.def_static("IsBRepEntity_", (Standard_Boolean (*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESToBRep::IsBRepEntity, "Return True if the IGESEntity can be transfered by TransferBRepEntity. ex: VertexList, EdgeList, Loop, Face, Shell, Manifold Solid BRep Object from IGESSolid : 502, 504, 508, 510, 514, 186.", py::arg("start"));
	cls_IGESToBRep.def_static("IGESCurveToSequenceOfIGESCurve_", (Standard_Integer (*)(const opencascade::handle<IGESData_IGESEntity> &, opencascade::handle<TColStd_HSequenceOfTransient> &)) &IGESToBRep::IGESCurveToSequenceOfIGESCurve, "None", py::arg("curve"), py::arg("sequence"));
	cls_IGESToBRep.def_static("TransferPCurve_", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Face &)) &IGESToBRep::TransferPCurve, "None", py::arg("fromedge"), py::arg("toedge"), py::arg("face"));


}
