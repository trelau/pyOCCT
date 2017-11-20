#include <pyOCCT_Common.hpp>

#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <GeomLProp_SurfaceTool.hxx>
#include <gp_Dir.hxx>
#include <GeomLProp_SLProps.hxx>
#include <Geom_Curve.hxx>
#include <GeomLProp_CurveTool.hxx>
#include <GeomLProp_CLProps.hxx>
#include <GeomAbs_Shape.hxx>
#include <GeomLProp.hxx>

PYBIND11_MODULE(GeomLProp, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.GeomAbs");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomLProp_SurfaceTool.hxx
	py::class_<GeomLProp_SurfaceTool, std::unique_ptr<GeomLProp_SurfaceTool, Deleter<GeomLProp_SurfaceTool>>> cls_GeomLProp_SurfaceTool(mod, "GeomLProp_SurfaceTool", "None");
	cls_GeomLProp_SurfaceTool.def(py::init<>());
	cls_GeomLProp_SurfaceTool.def_static("Value_", (void (*)(const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, gp_Pnt &)) &GeomLProp_SurfaceTool::Value, "Computes the point <P> of parameter <U> and <V> on the Surface <S>.", py::arg("S"), py::arg("U"), py::arg("V"), py::arg("P"));
	cls_GeomLProp_SurfaceTool.def_static("D1_", (void (*)(const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &)) &GeomLProp_SurfaceTool::D1, "Computes the point <P> and first derivative <D1*> of parameter <U> and <V> on the Surface <S>.", py::arg("S"), py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"));
	cls_GeomLProp_SurfaceTool.def_static("D2_", (void (*)(const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomLProp_SurfaceTool::D2, "Computes the point <P>, the first derivative <D1*> and second derivative <D2*> of parameter <U> and <V> on the Surface <S>.", py::arg("S"), py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("DUV"));
	cls_GeomLProp_SurfaceTool.def_static("DN_", (gp_Vec (*)(const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer)) &GeomLProp_SurfaceTool::DN, "None", py::arg("S"), py::arg("U"), py::arg("V"), py::arg("IU"), py::arg("IV"));
	cls_GeomLProp_SurfaceTool.def_static("Continuity_", (Standard_Integer (*)(const opencascade::handle<Geom_Surface> &)) &GeomLProp_SurfaceTool::Continuity, "returns the order of continuity of the Surface <S>. returns 1 : first derivative only is computable returns 2 : first and second derivative only are computable.", py::arg("S"));
	cls_GeomLProp_SurfaceTool.def_static("Bounds_", [](const opencascade::handle<Geom_Surface> & S, Standard_Real & U1, Standard_Real & V1, Standard_Real & U2, Standard_Real & V2){ GeomLProp_SurfaceTool::Bounds(S, U1, V1, U2, V2); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(U1, V1, U2, V2); }, "returns the bounds of the Surface.", py::arg("S"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomLProp_SLProps.hxx
	py::class_<GeomLProp_SLProps, std::unique_ptr<GeomLProp_SLProps, Deleter<GeomLProp_SLProps>>> cls_GeomLProp_SLProps(mod, "GeomLProp_SLProps", "None");
	cls_GeomLProp_SLProps.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("S"), py::arg("U"), py::arg("V"), py::arg("N"), py::arg("Resolution"));
	cls_GeomLProp_SLProps.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Integer, const Standard_Real>(), py::arg("S"), py::arg("N"), py::arg("Resolution"));
	cls_GeomLProp_SLProps.def(py::init<const Standard_Integer, const Standard_Real>(), py::arg("N"), py::arg("Resolution"));
	cls_GeomLProp_SLProps.def("SetSurface", (void (GeomLProp_SLProps::*)(const opencascade::handle<Geom_Surface> &)) &GeomLProp_SLProps::SetSurface, "Initializes the local properties of the surface S for the new surface.", py::arg("S"));
	cls_GeomLProp_SLProps.def("SetParameters", (void (GeomLProp_SLProps::*)(const Standard_Real, const Standard_Real)) &GeomLProp_SLProps::SetParameters, "Initializes the local properties of the surface S for the new parameter values (<U>, <V>).", py::arg("U"), py::arg("V"));
	cls_GeomLProp_SLProps.def("Value", (const gp_Pnt & (GeomLProp_SLProps::*)() const ) &GeomLProp_SLProps::Value, "Returns the point.");
	cls_GeomLProp_SLProps.def("D1U", (const gp_Vec & (GeomLProp_SLProps::*)()) &GeomLProp_SLProps::D1U, "Returns the first U derivative. The derivative is computed if it has not been yet.");
	cls_GeomLProp_SLProps.def("D1V", (const gp_Vec & (GeomLProp_SLProps::*)()) &GeomLProp_SLProps::D1V, "Returns the first V derivative. The derivative is computed if it has not been yet.");
	cls_GeomLProp_SLProps.def("D2U", (const gp_Vec & (GeomLProp_SLProps::*)()) &GeomLProp_SLProps::D2U, "Returns the second U derivatives The derivative is computed if it has not been yet.");
	cls_GeomLProp_SLProps.def("D2V", (const gp_Vec & (GeomLProp_SLProps::*)()) &GeomLProp_SLProps::D2V, "Returns the second V derivative. The derivative is computed if it has not been yet.");
	cls_GeomLProp_SLProps.def("DUV", (const gp_Vec & (GeomLProp_SLProps::*)()) &GeomLProp_SLProps::DUV, "Returns the second UV cross-derivative. The derivative is computed if it has not been yet.");
	cls_GeomLProp_SLProps.def("IsTangentUDefined", (Standard_Boolean (GeomLProp_SLProps::*)()) &GeomLProp_SLProps::IsTangentUDefined, "returns True if the U tangent is defined. For example, the tangent is not defined if the two first U derivatives are null.");
	cls_GeomLProp_SLProps.def("TangentU", (void (GeomLProp_SLProps::*)(gp_Dir &)) &GeomLProp_SLProps::TangentU, "Returns the tangent direction <D> on the iso-V.", py::arg("D"));
	cls_GeomLProp_SLProps.def("IsTangentVDefined", (Standard_Boolean (GeomLProp_SLProps::*)()) &GeomLProp_SLProps::IsTangentVDefined, "returns if the V tangent is defined. For example, the tangent is not defined if the two first V derivatives are null.");
	cls_GeomLProp_SLProps.def("TangentV", (void (GeomLProp_SLProps::*)(gp_Dir &)) &GeomLProp_SLProps::TangentV, "Returns the tangent direction <D> on the iso-V.", py::arg("D"));
	cls_GeomLProp_SLProps.def("IsNormalDefined", (Standard_Boolean (GeomLProp_SLProps::*)()) &GeomLProp_SLProps::IsNormalDefined, "Tells if the normal is defined.");
	cls_GeomLProp_SLProps.def("Normal", (const gp_Dir & (GeomLProp_SLProps::*)()) &GeomLProp_SLProps::Normal, "Returns the normal direction.");
	cls_GeomLProp_SLProps.def("IsCurvatureDefined", (Standard_Boolean (GeomLProp_SLProps::*)()) &GeomLProp_SLProps::IsCurvatureDefined, "returns True if the curvature is defined.");
	cls_GeomLProp_SLProps.def("IsUmbilic", (Standard_Boolean (GeomLProp_SLProps::*)()) &GeomLProp_SLProps::IsUmbilic, "returns True if the point is umbilic (i.e. if the curvature is constant).");
	cls_GeomLProp_SLProps.def("MaxCurvature", (Standard_Real (GeomLProp_SLProps::*)()) &GeomLProp_SLProps::MaxCurvature, "Returns the maximum curvature");
	cls_GeomLProp_SLProps.def("MinCurvature", (Standard_Real (GeomLProp_SLProps::*)()) &GeomLProp_SLProps::MinCurvature, "Returns the minimum curvature");
	cls_GeomLProp_SLProps.def("CurvatureDirections", (void (GeomLProp_SLProps::*)(gp_Dir &, gp_Dir &)) &GeomLProp_SLProps::CurvatureDirections, "Returns the direction of the maximum and minimum curvature <MaxD> and <MinD>", py::arg("MaxD"), py::arg("MinD"));
	cls_GeomLProp_SLProps.def("MeanCurvature", (Standard_Real (GeomLProp_SLProps::*)()) &GeomLProp_SLProps::MeanCurvature, "Returns the mean curvature.");
	cls_GeomLProp_SLProps.def("GaussianCurvature", (Standard_Real (GeomLProp_SLProps::*)()) &GeomLProp_SLProps::GaussianCurvature, "Returns the Gaussian curvature");

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomLProp_CurveTool.hxx
	py::class_<GeomLProp_CurveTool, std::unique_ptr<GeomLProp_CurveTool, Deleter<GeomLProp_CurveTool>>> cls_GeomLProp_CurveTool(mod, "GeomLProp_CurveTool", "None");
	cls_GeomLProp_CurveTool.def(py::init<>());
	cls_GeomLProp_CurveTool.def_static("Value_", (void (*)(const opencascade::handle<Geom_Curve> &, const Standard_Real, gp_Pnt &)) &GeomLProp_CurveTool::Value, "Computes the point <P> of parameter <U> on the curve <C>.", py::arg("C"), py::arg("U"), py::arg("P"));
	cls_GeomLProp_CurveTool.def_static("D1_", (void (*)(const opencascade::handle<Geom_Curve> &, const Standard_Real, gp_Pnt &, gp_Vec &)) &GeomLProp_CurveTool::D1, "Computes the point <P> and first derivative <V1> of parameter <U> on the curve <C>.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"));
	cls_GeomLProp_CurveTool.def_static("D2_", (void (*)(const opencascade::handle<Geom_Curve> &, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &)) &GeomLProp_CurveTool::D2, "Computes the point <P>, the first derivative <V1> and second derivative <V2> of parameter <U> on the curve <C>.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
	cls_GeomLProp_CurveTool.def_static("D3_", (void (*)(const opencascade::handle<Geom_Curve> &, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomLProp_CurveTool::D3, "Computes the point <P>, the first derivative <V1>, the second derivative <V2> and third derivative <V3> of parameter <U> on the curve <C>.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
	cls_GeomLProp_CurveTool.def_static("Continuity_", (Standard_Integer (*)(const opencascade::handle<Geom_Curve> &)) &GeomLProp_CurveTool::Continuity, "returns the order of continuity of the curve <C>. returns 1 : first derivative only is computable returns 2 : first and second derivative only are computable. returns 3 : first, second and third are computable.", py::arg("C"));
	cls_GeomLProp_CurveTool.def_static("FirstParameter_", (Standard_Real (*)(const opencascade::handle<Geom_Curve> &)) &GeomLProp_CurveTool::FirstParameter, "returns the first parameter bound of the curve.", py::arg("C"));
	cls_GeomLProp_CurveTool.def_static("LastParameter_", (Standard_Real (*)(const opencascade::handle<Geom_Curve> &)) &GeomLProp_CurveTool::LastParameter, "returns the last parameter bound of the curve. FirstParameter must be less than LastParamenter.", py::arg("C"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomLProp_CLProps.hxx
	py::class_<GeomLProp_CLProps, std::unique_ptr<GeomLProp_CLProps, Deleter<GeomLProp_CLProps>>> cls_GeomLProp_CLProps(mod, "GeomLProp_CLProps", "None");
	cls_GeomLProp_CLProps.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Integer, const Standard_Real>(), py::arg("C"), py::arg("N"), py::arg("Resolution"));
	cls_GeomLProp_CLProps.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("C"), py::arg("U"), py::arg("N"), py::arg("Resolution"));
	cls_GeomLProp_CLProps.def(py::init<const Standard_Integer, const Standard_Real>(), py::arg("N"), py::arg("Resolution"));
	cls_GeomLProp_CLProps.def("SetParameter", (void (GeomLProp_CLProps::*)(const Standard_Real)) &GeomLProp_CLProps::SetParameter, "Initializes the local properties of the curve for the parameter value <U>.", py::arg("U"));
	cls_GeomLProp_CLProps.def("SetCurve", (void (GeomLProp_CLProps::*)(const opencascade::handle<Geom_Curve> &)) &GeomLProp_CLProps::SetCurve, "Initializes the local properties of the curve for the new curve.", py::arg("C"));
	cls_GeomLProp_CLProps.def("Value", (const gp_Pnt & (GeomLProp_CLProps::*)() const ) &GeomLProp_CLProps::Value, "Returns the Point.");
	cls_GeomLProp_CLProps.def("D1", (const gp_Vec & (GeomLProp_CLProps::*)()) &GeomLProp_CLProps::D1, "Returns the first derivative. The derivative is computed if it has not been yet.");
	cls_GeomLProp_CLProps.def("D2", (const gp_Vec & (GeomLProp_CLProps::*)()) &GeomLProp_CLProps::D2, "Returns the second derivative. The derivative is computed if it has not been yet.");
	cls_GeomLProp_CLProps.def("D3", (const gp_Vec & (GeomLProp_CLProps::*)()) &GeomLProp_CLProps::D3, "Returns the third derivative. The derivative is computed if it has not been yet.");
	cls_GeomLProp_CLProps.def("IsTangentDefined", (Standard_Boolean (GeomLProp_CLProps::*)()) &GeomLProp_CLProps::IsTangentDefined, "Returns True if the tangent is defined. For example, the tangent is not defined if the three first derivatives are all null.");
	cls_GeomLProp_CLProps.def("Tangent", (void (GeomLProp_CLProps::*)(gp_Dir &)) &GeomLProp_CLProps::Tangent, "output the tangent direction <D>", py::arg("D"));
	cls_GeomLProp_CLProps.def("Curvature", (Standard_Real (GeomLProp_CLProps::*)()) &GeomLProp_CLProps::Curvature, "Returns the curvature.");
	cls_GeomLProp_CLProps.def("Normal", (void (GeomLProp_CLProps::*)(gp_Dir &)) &GeomLProp_CLProps::Normal, "Returns the normal direction <N>.", py::arg("N"));
	cls_GeomLProp_CLProps.def("CentreOfCurvature", (void (GeomLProp_CLProps::*)(gp_Pnt &)) &GeomLProp_CLProps::CentreOfCurvature, "Returns the centre of curvature <P>.", py::arg("P"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomLProp.hxx
	py::class_<GeomLProp, std::unique_ptr<GeomLProp, Deleter<GeomLProp>>> cls_GeomLProp(mod, "GeomLProp", "These global functions compute the degree of continuity of a 3D curve built by concatenation of two other curves (or portions of curves) at their junction point.");
	cls_GeomLProp.def(py::init<>());
	cls_GeomLProp.def_static("Continuity_", (GeomAbs_Shape (*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Real, const Standard_Real)) &GeomLProp::Continuity, "Computes the regularity at the junction between C1 and C2. The booleans r1 and r2 are true if the curves must be taken reversed. The point u1 on C1 and the point u2 on C2 must be confused. tl and ta are the linear and angular tolerance used two compare the derivative.", py::arg("C1"), py::arg("C2"), py::arg("u1"), py::arg("u2"), py::arg("r1"), py::arg("r2"), py::arg("tl"), py::arg("ta"));
	cls_GeomLProp.def_static("Continuity_", (GeomAbs_Shape (*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean)) &GeomLProp::Continuity, "The same as preciding but using the standard tolerances from package Precision.", py::arg("C1"), py::arg("C2"), py::arg("u1"), py::arg("u2"), py::arg("r1"), py::arg("r2"));


}
