rules = [
    {"factor": "Attendance", "score": "Excellent", "recommendation": "Reward employee for exceptional attendance."},
    {"factor": "Attendance", "score": "Good", "recommendation": "Acknowledge employee's good attendance."},
    {"factor": "Attendance", "score": "Needs Improvement", "recommendation": "Discuss attendance concerns and set improvement goals."},
    {"factor": "Productivity", "score": "Excellent", "recommendation": "Recognize and encourage employee's high productivity."},
    {"factor": "Productivity", "score": "Good", "recommendation": "Maintain employee's good productivity level."},
    {"factor": "Productivity", "score": "Needs Improvement", "recommendation": "Provide additional support and resources to improve productivity."},
    {"factor": "Communication", "score": "Excellent", "recommendation": "Promote employee's strong communication skills."},
    {"factor": "Communication", "score": "Good", "recommendation": "Encourage employee to continue effective communication."},
    {"factor": "Communication", "score": "Needs Improvement", "recommendation": "Offer training or mentoring to enhance communication abilities."},
]

def process_input(factor, score):
    matching_rules = []
    for rule in rules:
        if rule["factor"] == factor and rule["score"] == score:
            matching_rules.append(rule)

    if len(matching_rules) == 0:
        return "No matching factor and score combination found."

    recommendations = []
    for rule in matching_rules:
        recommendations.append(rule["recommendation"])

    return ", ".join(recommendations)

user_factor = input("Enter the performance factor: ")
user_score = input("Enter the score (Excellent, Good, Needs Improvement): ")

output = process_input(user_factor, user_score)
print(output)
