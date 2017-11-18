#include <pyOCCT_Common.hpp>

#include <Standard_Handle.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <LProp3d_CurveTool.hxx>
#include <gp_Dir.hxx>
#include <LProp3d_CLProps.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <LProp3d_SurfaceTool.hxx>
#include <LProp3d_SLProps.hxx>

PYBIND11_MODULE(LProp3d, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.Adaptor3d");
	py::module::import("OCCT.gp");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\LProp3d_CurveTool.hxx
	py::class_<LProp3d_CurveTool, std::unique_ptr<LProp3d_CurveTool, Deleter<LProp3d_CurveTool>>> cls_LProp3d_CurveTool(mod, "LProp3d_CurveTool", "None");
	cls_LProp3d_CurveTool.def(py::init<>());
	cls_LProp3d_CurveTool.def_static("Value_", (void (*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, gp_Pnt &)) &LProp3d_CurveTool::Value, "Computes the point <P> of parameter <U> on the HCurve <C>.", py::arg("C"), py::arg("U"), py::arg("P"));
	cls_LProp3d_CurveTool.def_static("D1_", (void (*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, gp_Pnt &, gp_Vec &)) &LProp3d_CurveTool::D1, "Computes the point <P> and first derivative <V1> of parameter <U> on the HCurve <C>.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"));
	cls_LProp3d_CurveTool.def_static("D2_", (void (*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &)) &LProp3d_CurveTool::D2, "Computes the point <P>, the first derivative <V1> and second derivative <V2> of parameter <U> on the HCurve <C>.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
	cls_LProp3d_CurveTool.def_static("D3_", (void (*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &)) &LProp3d_CurveTool::D3, "Computes the point <P>, the first derivative <V1>, the second derivative <V2> and third derivative <V3> of parameter <U> on the HCurve <C>.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
	cls_LProp3d_CurveTool.def_static("Continuity_", (Standard_Integer (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &LProp3d_CurveTool::Continuity, "returns the order of continuity of the HCurve <C>. returns 1 : first derivative only is computable returns 2 : first and second derivative only are computable. returns 3 : first, second and third are computable.", py::arg("C"));
	cls_LProp3d_CurveTool.def_static("FirstParameter_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &LProp3d_CurveTool::FirstParameter, "returns the first parameter bound of the HCurve.", py::arg("C"));
	cls_LProp3d_CurveTool.def_static("LastParameter_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &LProp3d_CurveTool::LastParameter, "returns the last parameter bound of the HCurve. FirstParameter must be less than LastParamenter.", py::arg("C"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\LProp3d_CLProps.hxx
	py::class_<LProp3d_CLProps, std::unique_ptr<LProp3d_CLProps, Deleter<LProp3d_CLProps>>> cls_LProp3d_CLProps(mod, "LProp3d_CLProps", "None");
	cls_LProp3d_CLProps.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Integer, const Standard_Real>(), py::arg("C"), py::arg("N"), py::arg("Resolution"));
	cls_LProp3d_CLProps.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("C"), py::arg("U"), py::arg("N"), py::arg("Resolution"));
	cls_LProp3d_CLProps.def(py::init<const Standard_Integer, const Standard_Real>(), py::arg("N"), py::arg("Resolution"));
	cls_LProp3d_CLProps.def("SetParameter", (void (LProp3d_CLProps::*)(const Standard_Real)) &LProp3d_CLProps::SetParameter, "Initializes the local properties of the curve for the parameter value <U>.", py::arg("U"));
	cls_LProp3d_CLProps.def("SetCurve", (void (LProp3d_CLProps::*)(const opencascade::handle<Adaptor3d_HCurve> &)) &LProp3d_CLProps::SetCurve, "Initializes the local properties of the curve for the new curve.", py::arg("C"));
	cls_LProp3d_CLProps.def("Value", (const gp_Pnt & (LProp3d_CLProps::*)() const ) &LProp3d_CLProps::Value, "Returns the Point.");
	cls_LProp3d_CLProps.def("D1", (const gp_Vec & (LProp3d_CLProps::*)()) &LProp3d_CLProps::D1, "Returns the first derivative. The derivative is computed if it has not been yet.");
	cls_LProp3d_CLProps.def("D2", (const gp_Vec & (LProp3d_CLProps::*)()) &LProp3d_CLProps::D2, "Returns the second derivative. The derivative is computed if it has not been yet.");
	cls_LProp3d_CLProps.def("D3", (const gp_Vec & (LProp3d_CLProps::*)()) &LProp3d_CLProps::D3, "Returns the third derivative. The derivative is computed if it has not been yet.");
	cls_LProp3d_CLProps.def("IsTangentDefined", (Standard_Boolean (LProp3d_CLProps::*)()) &LProp3d_CLProps::IsTangentDefined, "Returns True if the tangent is defined. For example, the tangent is not defined if the three first derivatives are all null.");
	cls_LProp3d_CLProps.def("Tangent", (void (LProp3d_CLProps::*)(gp_Dir &)) &LProp3d_CLProps::Tangent, "output the tangent direction <D>", py::arg("D"));
	cls_LProp3d_CLProps.def("Curvature", (Standard_Real (LProp3d_CLProps::*)()) &LProp3d_CLProps::Curvature, "Returns the curvature.");
	cls_LProp3d_CLProps.def("Normal", (void (LProp3d_CLProps::*)(gp_Dir &)) &LProp3d_CLProps::Normal, "Returns the normal direction <N>.", py::arg("N"));
	cls_LProp3d_CLProps.def("CentreOfCurvature", (void (LProp3d_CLProps::*)(gp_Pnt &)) &LProp3d_CLProps::CentreOfCurvature, "Returns the centre of curvature <P>.", py::arg("P"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\LProp3d_SurfaceTool.hxx
	py::class_<LProp3d_SurfaceTool, std::unique_ptr<LProp3d_SurfaceTool, Deleter<LProp3d_SurfaceTool>>> cls_LProp3d_SurfaceTool(mod, "LProp3d_SurfaceTool", "None");
	cls_LProp3d_SurfaceTool.def(py::init<>());
	cls_LProp3d_SurfaceTool.def_static("Value_", (void (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real, gp_Pnt &)) &LProp3d_SurfaceTool::Value, "Computes the point <P> of parameter <U> and <V> on the HSurface <S>.", py::arg("S"), py::arg("U"), py::arg("V"), py::arg("P"));
	cls_LProp3d_SurfaceTool.def_static("D1_", (void (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &)) &LProp3d_SurfaceTool::D1, "Computes the point <P> and first derivative <D1*> of parameter <U> and <V> on the HSurface <S>.", py::arg("S"), py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"));
	cls_LProp3d_SurfaceTool.def_static("D2_", (void (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &LProp3d_SurfaceTool::D2, "Computes the point <P>, the first derivative <D1*> and second derivative <D2*> of parameter <U> and <V> on the HSurface <S>.", py::arg("S"), py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("DUV"));
	cls_LProp3d_SurfaceTool.def_static("DN_", (gp_Vec (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer)) &LProp3d_SurfaceTool::DN, "None", py::arg("S"), py::arg("U"), py::arg("V"), py::arg("IU"), py::arg("IV"));
	cls_LProp3d_SurfaceTool.def_static("Continuity_", (Standard_Integer (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &LProp3d_SurfaceTool::Continuity, "returns the order of continuity of the HSurface <S>. returns 1 : first derivative only is computable returns 2 : first and second derivative only are computable.", py::arg("S"));
	cls_LProp3d_SurfaceTool.def_static("Bounds_", (void (*)(const opencascade::handle<Adaptor3d_HSurface> &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &)) &LProp3d_SurfaceTool::Bounds, "returns the bounds of the HSurface.", py::arg("S"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\LProp3d_SLProps.hxx
	py::class_<LProp3d_SLProps, std::unique_ptr<LProp3d_SLProps, Deleter<LProp3d_SLProps>>> cls_LProp3d_SLProps(mod, "LProp3d_SLProps", "None");
	cls_LProp3d_SLProps.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("S"), py::arg("U"), py::arg("V"), py::arg("N"), py::arg("Resolution"));
	cls_LProp3d_SLProps.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Integer, const Standard_Real>(), py::arg("S"), py::arg("N"), py::arg("Resolution"));
	cls_LProp3d_SLProps.def(py::init<const Standard_Integer, const Standard_Real>(), py::arg("N"), py::arg("Resolution"));
	cls_LProp3d_SLProps.def("SetSurface", (void (LProp3d_SLProps::*)(const opencascade::handle<Adaptor3d_HSurface> &)) &LProp3d_SLProps::SetSurface, "Initializes the local properties of the surface S for the new surface.", py::arg("S"));
	cls_LProp3d_SLProps.def("SetParameters", (void (LProp3d_SLProps::*)(const Standard_Real, const Standard_Real)) &LProp3d_SLProps::SetParameters, "Initializes the local properties of the surface S for the new parameter values (<U>, <V>).", py::arg("U"), py::arg("V"));
	cls_LProp3d_SLProps.def("Value", (const gp_Pnt & (LProp3d_SLProps::*)() const ) &LProp3d_SLProps::Value, "Returns the point.");
	cls_LProp3d_SLProps.def("D1U", (const gp_Vec & (LProp3d_SLProps::*)()) &LProp3d_SLProps::D1U, "Returns the first U derivative. The derivative is computed if it has not been yet.");
	cls_LProp3d_SLProps.def("D1V", (const gp_Vec & (LProp3d_SLProps::*)()) &LProp3d_SLProps::D1V, "Returns the first V derivative. The derivative is computed if it has not been yet.");
	cls_LProp3d_SLProps.def("D2U", (const gp_Vec & (LProp3d_SLProps::*)()) &LProp3d_SLProps::D2U, "Returns the second U derivatives The derivative is computed if it has not been yet.");
	cls_LProp3d_SLProps.def("D2V", (const gp_Vec & (LProp3d_SLProps::*)()) &LProp3d_SLProps::D2V, "Returns the second V derivative. The derivative is computed if it has not been yet.");
	cls_LProp3d_SLProps.def("DUV", (const gp_Vec & (LProp3d_SLProps::*)()) &LProp3d_SLProps::DUV, "Returns the second UV cross-derivative. The derivative is computed if it has not been yet.");
	cls_LProp3d_SLProps.def("IsTangentUDefined", (Standard_Boolean (LProp3d_SLProps::*)()) &LProp3d_SLProps::IsTangentUDefined, "returns True if the U tangent is defined. For example, the tangent is not defined if the two first U derivatives are null.");
	cls_LProp3d_SLProps.def("TangentU", (void (LProp3d_SLProps::*)(gp_Dir &)) &LProp3d_SLProps::TangentU, "Returns the tangent direction <D> on the iso-V.", py::arg("D"));
	cls_LProp3d_SLProps.def("IsTangentVDefined", (Standard_Boolean (LProp3d_SLProps::*)()) &LProp3d_SLProps::IsTangentVDefined, "returns if the V tangent is defined. For example, the tangent is not defined if the two first V derivatives are null.");
	cls_LProp3d_SLProps.def("TangentV", (void (LProp3d_SLProps::*)(gp_Dir &)) &LProp3d_SLProps::TangentV, "Returns the tangent direction <D> on the iso-V.", py::arg("D"));
	cls_LProp3d_SLProps.def("IsNormalDefined", (Standard_Boolean (LProp3d_SLProps::*)()) &LProp3d_SLProps::IsNormalDefined, "Tells if the normal is defined.");
	cls_LProp3d_SLProps.def("Normal", (const gp_Dir & (LProp3d_SLProps::*)()) &LProp3d_SLProps::Normal, "Returns the normal direction.");
	cls_LProp3d_SLProps.def("IsCurvatureDefined", (Standard_Boolean (LProp3d_SLProps::*)()) &LProp3d_SLProps::IsCurvatureDefined, "returns True if the curvature is defined.");
	cls_LProp3d_SLProps.def("IsUmbilic", (Standard_Boolean (LProp3d_SLProps::*)()) &LProp3d_SLProps::IsUmbilic, "returns True if the point is umbilic (i.e. if the curvature is constant).");
	cls_LProp3d_SLProps.def("MaxCurvature", (Standard_Real (LProp3d_SLProps::*)()) &LProp3d_SLProps::MaxCurvature, "Returns the maximum curvature");
	cls_LProp3d_SLProps.def("MinCurvature", (Standard_Real (LProp3d_SLProps::*)()) &LProp3d_SLProps::MinCurvature, "Returns the minimum curvature");
	cls_LProp3d_SLProps.def("CurvatureDirections", (void (LProp3d_SLProps::*)(gp_Dir &, gp_Dir &)) &LProp3d_SLProps::CurvatureDirections, "Returns the direction of the maximum and minimum curvature <MaxD> and <MinD>", py::arg("MaxD"), py::arg("MinD"));
	cls_LProp3d_SLProps.def("MeanCurvature", (Standard_Real (LProp3d_SLProps::*)()) &LProp3d_SLProps::MeanCurvature, "Returns the mean curvature.");
	cls_LProp3d_SLProps.def("GaussianCurvature", (Standard_Real (LProp3d_SLProps::*)()) &LProp3d_SLProps::GaussianCurvature, "Returns the Gaussian curvature");


}
